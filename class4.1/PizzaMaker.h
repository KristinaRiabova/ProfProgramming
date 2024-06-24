#ifndef PIZZAMAKER_H
#define PIZZAMAKER_H

#include "CustomPizzaBuilder.h"

class PizzaMaker {
public:
    void createPizza(CustomPizzaBuilder& builder, const std::vector<std::string>& toppings);
};

#endif
