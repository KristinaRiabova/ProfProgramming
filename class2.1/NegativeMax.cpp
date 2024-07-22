#include <ranges> // We are using built-in mechanism to process checks, filtering and transformations(ranges, views, etc).
#include <print> // We can use some short version of names like str in lambdas or other helper things
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::println("Enter the list of numbers separated by comma:"); // We are using readable names(inputString, delimeter) which allows us to increase code readability.

    std::string inputString;
    std::getline(std::cin, inputString);

    constexpr std::string_view delimiter(","); // We are using readable names(inputString, delimeter) which allows us to increase code readability.

    auto filteredValues = std::views::split(inputString, delimiter)
        | std::ranges::to<std::vector<std::string>>()
        | std::views::filter([](const auto& str) { try { return std::stod(str) < 0; } catch (const std::exception& e) { return false; } }) // We can write lambda with try catch as a one-liner cause the main info is in try block.
        | std::ranges::views::transform([](const auto& str) { return std::stod(str); })
        | std::ranges::to<std::vector>();

    if (filteredValues.empty()) {
        std::println("No negative values in the list or incorrect input format"); // We don't even need additional comments in the code as they will only duplicate what is already present and can be read from it.
    }
    else {
        std::println("Result is {}", std::ranges::max(filteredValues)); // We split logical blocks in code with empty lines - it allows us to structure the steps visually.
    }
}


