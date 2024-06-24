#ifndef MEGADATAPOOL_H
#define MEGADATAPOOL_H

#include "MegaData.h"
#include <vector>

class MegaDataPool {
private:
    std::vector<MegaData> pool;
    std::vector<bool> available;
    int poolSize;
    int usedCount;

public:
    MegaDataPool(int size);

    MegaData* acquire();
    void release(MegaData* megadata);

    int size() const;
    int usedSize() const;
};

#endif
