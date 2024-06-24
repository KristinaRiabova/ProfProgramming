#ifndef MEGADATAPOOL_H
#define MEGADATAPOOL_H

#include "MegaData.h"
#include <vector>
#include <mutex>

class MegaDataPool {
private:
    std::vector<MegaData> pool;
    std::vector<bool> available;
    int poolSize;
    int usedCount;
    std::mutex mtx;

    MegaDataPool(int size); // Private constructor

public:
    static MegaDataPool& getInstance(int size);

    MegaData* acquire();
    void release(MegaData* megadata);

    int size() const;
    int usedSize() const;
};

#endif
