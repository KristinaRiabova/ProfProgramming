#ifndef MEGADATA_H
#define MEGADATA_H

#include <array>

class MegaData {
private:
    std::array<float, 1024> smallArray;
    std::array<double, 1024 * 1024> bigArray;

public:
    MegaData();

    void reset();

    std::array<float, 1024>& getSmallArray();
    std::array<double, 1024 * 1024>& getBigArray();
};

#endif
