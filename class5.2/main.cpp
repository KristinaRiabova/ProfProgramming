#include "MegaDataPool.h"
#include <iostream>
#include <thread>
#include <chrono>

void threadFunction(int threadId) {
    MegaDataPool& pool = MegaDataPool::getInstance(5); // Singleton instance with pool size 5

    MegaData* data = pool.acquire();
    if (data) {
        std::array<float, 1024>& smallArr = data->getSmallArray();
        smallArr[0] = threadId; // Simulate modifying data

        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        pool.release(data);
    }
}

int main() {
    constexpr int numThreads = 10;
    std::thread threads[numThreads];

    // Start threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(threadFunction, i);
    }

    // Join threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // Output pool statistics
    MegaDataPool& pool = MegaDataPool::getInstance(5);
    std::cout << "Pool size: " << pool.size() << std::endl;
    std::cout << "Objects used: " << pool.usedSize() << std::endl;

    return 0;
}
