#ifndef CUSTOMPIZZA_H
#define CUSTOMPIZZA_H

#include <vector>
#include <string>
#include <iostream>

class CustomPizza {
public:
    void addTopping(const std::string& topping, double cost);
    void display() const;
    double getTotalCost() const;

private:
    std::vector<std::string> toppings;
    double totalCost = 0.0;
};

#endif 
