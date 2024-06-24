#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <vector>
#include <random>
#include <chrono>


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


class MessageSubscriber {
public:
    virtual ~MessageSubscriber() {}
    virtual void handleMessage(const GreenMessage& msg) = 0;
    virtual void handleMessage(const BlueMessage& msg) = 0;
    virtual void handleMessage(const OrangeMessage& msg) = 0;
};


class MessageDispatcher {
public:

    void subscribe(MessageSubscriber* subscriber) {
        std::lock_guard<std::mutex> lock(mutex_);
        subscribers_.push_back(subscriber);
    }


    void publish(const GreenMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto subscriber : subscribers_) {
            subscriber->handleMessage(message);
        }
    }


    void publish(const BlueMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto subscriber : subscribers_) {
            subscriber->handleMessage(message);
        }
    }


    void publish(const OrangeMessage& message) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (auto subscriber : subscribers_) {
            subscriber->handleMessage(message);
        }
    }

private:
    std::mutex mutex_;
    std::vector<MessageSubscriber*> subscribers_;
};

// MessageGenerator class
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
        while (true) {
            GreenMessage msg = generateGreenMessage();
            dispatcher_.publish(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(376));
        }
    }

    void generateBlueMessages() {
        while (true) {
            BlueMessage msg = generateBlueMessage();
            dispatcher_.publish(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(473));
        }
    }

    void generateOrangeMessages() {
        while (true) {
            OrangeMessage msg = generateOrangeMessage();
            dispatcher_.publish(msg);
            std::this_thread::sleep_for(std::chrono::milliseconds(756));
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

// Example subscriber implementation
class ExampleSubscriber : public MessageSubscriber {
public:
    void handleMessage(const GreenMessage& msg) override {
        std::cout << "Received GreenMessage: " << msg.message << " " << msg.counter << std::endl;
    }

    void handleMessage(const BlueMessage& msg) override {
        std::cout << "Received BlueMessage: " << msg.value1 << " " << msg.value2 << std::endl;
    }

    void handleMessage(const OrangeMessage& msg) override {
        std::cout << "Received OrangeMessage: " << msg.str1 << " " << msg.str2 << " " << msg.number << " " << msg.value << std::endl;
    }
};

int main() {
    MessageDispatcher dispatcher;
    ExampleSubscriber subscriber;

    dispatcher.subscribe(&subscriber);

    MessageGenerator generator(dispatcher);
    generator.startGenerating();

  
    std::this_thread::sleep_for(std::chrono::seconds(10));

    generator.stopGenerating();

    return 0;
}
