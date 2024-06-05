#include "Helpers.hpp"
#include <algorithm>

double dummyFunc(double x) {
    return x > 0 ? x : 0;
}

std::string repeatString(const std::vector<int>& numbers, const std::string& str) {
    if (numbers.empty()) {
        return ""; // If the vector is empty, return an empty string
    }

    int maxNumber = *std::max_element(numbers.begin(), numbers.end()); // Find the maximum value in the vector

    if (maxNumber <= 0) {
        return ""; // If the maximum number is zero or negative, return an empty string
    }

    std::string repeatedString;
    for (int i = 0; i < maxNumber; ++i) {
        repeatedString += str;
    }

    return repeatedString;
}
