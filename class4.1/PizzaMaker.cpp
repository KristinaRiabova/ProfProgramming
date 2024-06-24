#include "PizzaMaker.h"

void PizzaMaker::createPizza(CustomPizzaBuilder& builder, const std::vector<std::string>& toppings) {
    for (const auto& topping : toppings) {
        builder.addTopping(topping);
    }
}
