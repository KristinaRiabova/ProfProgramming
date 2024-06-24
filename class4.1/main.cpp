#include "CustomPizzaBuilder.h"
#include "PizzaMaker.h"
#include <iostream>

int main() {
    CustomPizzaBuilder builder;
    PizzaMaker maker;

    std::vector<std::string> toppings;
    std::string input;

    std::cout << "Enter toppings (type 'done' when finished):" << std::endl;

    while (true) {
        std::cin >> input;
        if (input == "done") {
            break;
        }
        toppings.push_back(input);
    }

    maker.createPizza(builder, toppings);
    CustomPizza pizza = builder.getPizza();
    pizza.display();

    return 0;
}
