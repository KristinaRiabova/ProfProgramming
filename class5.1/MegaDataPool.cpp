#include "MegaDataPool.h"

MegaDataPool::MegaDataPool(int size) : poolSize(size), usedCount(0) {
    pool.resize(size);
    available.resize(size, true); // All objects are initially available
}

MegaData* MegaDataPool::acquire() {
    for (int i = 0; i < poolSize; ++i) {
        if (available[i]) {
            available[i] = false;
            usedCount++;
            return &pool[i];
        }
    }
    return nullptr; // No available objects in the pool
}

void MegaDataPool::release(MegaData* megadata) {
    // Release a MegaData object back to the pool
    for (int i = 0; i < poolSize; ++i) {
        if (&pool[i] == megadata) {
            available[i] = true;
            usedCount--;
            pool[i].reset(); // Reset the state of MegaData object
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
