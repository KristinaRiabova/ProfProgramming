#include "MegaData.h"

MegaData::MegaData() {
    smallArray.fill(42.0f);
    bigArray.fill(42.0);
}

void MegaData::reset() {
    smallArray.fill(42.0f);
    bigArray.fill(42.0);
}

std::array<float, 1024>& MegaData::getSmallArray() {
    return smallArray;
}

std::array<double, 1024 * 1024>& MegaData::getBigArray() {
    return bigArray;
}
