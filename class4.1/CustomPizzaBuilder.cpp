#include "CustomPizzaBuilder.h"

CustomPizzaBuilder::CustomPizzaBuilder() {
    loadToppings("ingredients.txt");
}

void CustomPizzaBuilder::addTopping(const std::string& topping) {
    if (toppingPrices.find(topping) != toppingPrices.end()) {
        pizza.addTopping(topping, toppingPrices[topping]);
    } else {
        std::cerr << "Topping not found: " << topping << std::endl;
    }
}

CustomPizza CustomPizzaBuilder::getPizza() const {
    return pizza;
}

void CustomPizzaBuilder::loadToppings(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string topping;
        double cost;
        if (iss >> topping >> cost) {
            toppingPrices[topping] = cost;
        }
    }
}
