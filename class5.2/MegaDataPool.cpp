#include "MegaDataPool.h"

MegaDataPool::MegaDataPool(int size) : poolSize(size), usedCount(0) {
    pool.resize(size);
    available.resize(size, true);
}

MegaDataPool& MegaDataPool::getInstance(int size) {
    static MegaDataPool instance(size);
    return instance;
}

MegaData* MegaDataPool::acquire() {
    std::lock_guard<std::mutex> lock(mtx);

    for (int i = 0; i < poolSize; ++i) {
        if (available[i]) {
            available[i] = false;
            usedCount++;
            return &pool[i];
        }
    }
    return nullptr;
}

void MegaDataPool::release(MegaData* megadata) {
    std::lock_guard<std::mutex> lock(mtx);

    for (int i = 0; i < poolSize; ++i) {
        if (&pool[i] == megadata) {
            available[i] = true;
            usedCount--;
            pool[i].reset();
            break;
        }
    }
}

int MegaDataPool::size() const {
    return poolSize;
}

int MegaDataPool::usedSize() const {
    return usedCount;
}
