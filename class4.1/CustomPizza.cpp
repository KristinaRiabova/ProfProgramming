#include "CustomPizza.h"

void CustomPizza::addTopping(const std::string& topping, double cost) {
    toppings.push_back(topping);
    totalCost += cost;
}

void CustomPizza::display() const {
    std::cout << "Toppings:" << std::endl;
    for (const auto& topping : toppings) {
        std::cout << "- " << topping << std::endl;
    }
    std::cout << "Total cost: $" << totalCost << std::endl;
}

double CustomPizza::getTotalCost() const {
    return totalCost;
}
