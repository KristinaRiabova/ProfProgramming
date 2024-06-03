#include "Helpers.hpp"
#include <algorithm>

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}
std::string repeatString(const std::vector<int>& integers, const std::string& str) {
    if (integers.empty()) {
        return "";
    }

    int maxInt = *std::max_element(integers.begin(), integers.end());
    return std::string(maxInt, ' ') + str;
}
