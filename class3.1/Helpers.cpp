#include "Helpers.hpp"
#include <algorithm>


std::string repeatString(const std::vector<int>& integers, const std::string& str) {
    if (integers.empty()) {
        return "";
    }

    int maxInt = *std::max_element(integers.begin(), integers.end());
    return std::string(maxInt, ' ') + str;
}
