#ifndef CUSTOMPIZZABUILDER_H
#define CUSTOMPIZZABUILDER_H

#include "CustomPizza.h"
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

class CustomPizzaBuilder {
public:
    CustomPizzaBuilder();
    void addTopping(const std::string& topping);
    CustomPizza getPizza() const;

private:
    CustomPizza pizza;
    std::unordered_map<std::string, double> toppingPrices;
    void loadToppings(const std::string& filename);
};

#endif 
