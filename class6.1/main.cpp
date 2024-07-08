#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <queue>
#include <random>
#include <chrono>
#include <memory>

struct GreenMessage {
    std::string message;
    int counter;
};

struct BlueMessage {
    double value1;
    double value2;
};

struct OrangeMessage {
    std::string str1;
    std::string str2;
    int number;
    double value;
};

using GreenCallback = std::function<void(const GreenMessage&)>;
using BlueCallback = std::function<void(const BlueMessage&)>;
using OrangeCallback = std::function<void(const OrangeMessage&)>;

class MessageDispatcher {
public:
    void subscribe(GreenCallback callback) {
        std::lock_guard<std::mutex> lock(mutex_);
        greenCallbacks_.push_back(std::move(callback));
    }

    void subscribe(BlueCallback callback) {
        std::lock_guard<std::mutex> lock(mutex_);
        blueCallbacks_.push_back(std::move(callback));
    }

    void subscribe(OrangeCallback callback) {
        std::lock_guard<std::mutex> lock(mutex_);
        orangeCallbacks_.push_back(std::move(callback));
    }

    void publish(const GreenMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        greenQueue_.push(message);
        cv_.notify_one();
    }

    void publish(const BlueMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        blueQueue_.push(message);
        cv_.notify_one();
    }

    void publish(const OrangeMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        orangeQueue_.push(message);
        cv_.notify_one();
    }

    void startDispatching() {
        dispatchThread_ = std::thread(&MessageDispatcher::dispatch, this);
    }

    void stopDispatching() {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        if (dispatchThread_.joinable()) {
            dispatchThread_.join();
        }
    }

private:
    void dispatch() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex_);
            cv_.wait(lock, [this] { return stop_ || !greenQueue_.empty() || !blueQueue_.empty() || !orangeQueue_.empty(); });

            if (stop_ && greenQueue_.empty() && blueQueue_.empty() && orangeQueue_.empty()) {
                break;
            }

            if (!greenQueue_.empty()) {
                GreenMessage message = greenQueue_.front();
                greenQueue_.pop();
                lock.unlock();
                for (const auto& callback : greenCallbacks_) {
                    callback(message);
                }
                lock.lock();
            }

            if (!blueQueue_.empty()) {
                BlueMessage message = blueQueue_.front();
                blueQueue_.pop();
                lock.unlock();
                for (const auto& callback : blueCallbacks_) {
                    callback(message);
                }
                lock.lock();
            }

            if (!orangeQueue_.empty()) {
                OrangeMessage message = orangeQueue_.front();
                orangeQueue_.pop();
                lock.unlock();
                for (const auto& callback : orangeCallbacks_) {
                    callback(message);
                }
                lock.lock();
            }
        }
    }

    std::mutex mutex_;
    std::condition_variable cv_;
    bool stop_ = false;
    std::thread dispatchThread_;

    std::queue<GreenMessage> greenQueue_;
    std::queue<BlueMessage> blueQueue_;
    std::queue<OrangeMessage> orangeQueue_;

    std::vector<GreenCallback> greenCallbacks_;
    std::vector<BlueCallback> blueCallbacks_;
    std::vector<OrangeCallback> orangeCallbacks_;
};


class MessageGenerator {
public:
    MessageGenerator(MessageDispatcher& dispatcher) : dispatcher_(dispatcher) {}

    void startGenerating() {
        greenThread_ = std::thread(&MessageGenerator::generateGreenMessages, this);
        blueThread_ = std::thread(&MessageGenerator::generateBlueMessages, this);
        orangeThread_ = std::thread(&MessageGenerator::generateOrangeMessages, this);
    }

    void stopGenerating() {
        if (greenThread_.joinable()) greenThread_.join();
        if (blueThread_.joinable()) blueThread_.join();
        if (orangeThread_.joinable()) orangeThread_.join();
    }

private:
    void generateGreenMessages() {
        constexpr auto delay = std::chrono::milliseconds(376);
        while (true) {
            GreenMessage msg = generateGreenMessage();
            dispatcher_.publish(msg);
            std::this_thread::sleep_for(delay);
        }
    }

    void generateBlueMessages() {
        constexpr auto delay = std::chrono::milliseconds(473);
        while (true) {
            BlueMessage msg = generateBlueMessage();
            dispatcher_.publish(msg);
            std::this_thread::sleep_for(delay);
        }
    }

    void generateOrangeMessages() {
        constexpr auto delay = std::chrono::milliseconds(756);
        while (true) {
            OrangeMessage msg = generateOrangeMessage();
            dispatcher_.publish(msg);
            std::this_thread::sleep_for(delay);
        }
    }

    GreenMessage generateGreenMessage() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> counterDist(1, 100);

        std::string msg = "Green Message";
        int counter = counterDist(gen);
        return { msg, counter };
    }

    BlueMessage generateBlueMessage() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_real_distribution<> valueDist(0.0, 1.0);

        double value1 = valueDist(gen);
        double value2 = valueDist(gen);
        return { value1, value2 };
    }

    OrangeMessage generateOrangeMessage() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> numberDist(1, 100);
        static std::uniform_real_distribution<> valueDist(0.0, 1.0);

        std::string str1 = "Orange";
        std::string str2 = "Message";
        int number = numberDist(gen);
        double value = valueDist(gen);
        return { str1, str2, number, value };
    }

    MessageDispatcher& dispatcher_;
    std::thread greenThread_;
    std::thread blueThread_;
    std::thread orangeThread_;
};

int main() {
    MessageDispatcher dispatcher;
    
    dispatcher.subscribe([](const GreenMessage& msg) {
        std::cout << "Received GreenMessage: " << msg.message << " " << msg.counter << std::endl;
    });

    dispatcher.subscribe([](const BlueMessage& msg) {
        std::cout << "Received BlueMessage: " << msg.value1 << " " << msg.value2 << std::endl;
    });

    dispatcher.subscribe([](const OrangeMessage& msg) {
        std::cout << "Received OrangeMessage: " << msg.str1 << " " << msg.str2 << " " << msg.number << " " << msg.value << std::endl;
    });

    dispatcher.startDispatching();

    MessageGenerator generator(dispatcher);
    generator.startGenerating();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    generator.stopGenerating();
    dispatcher.stopDispatching();

    return 0;
}
