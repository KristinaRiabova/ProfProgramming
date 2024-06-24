#include "CustomPizza.h"
#include "CustomPizzaBuilder.h"
#include "PizzaMaker.h"
#include <gtest/gtest.h>

TEST(CustomPizzaTest, AddTopping) {
    CustomPizza pizza;
    pizza.addTopping("Pepperoni", 2.0);
    EXPECT_EQ(pizza.getTotalCost(), 2.0);
}

TEST(CustomPizzaBuilderTest, AddTopping) {
    CustomPizzaBuilder builder;
    builder.addTopping("Pepperoni");
    CustomPizza pizza = builder.getPizza();
    EXPECT_EQ(pizza.getTotalCost(), 2.0);
}

TEST(PizzaMakerTest, CreatePizza) {
    CustomPizzaBuilder builder;
    PizzaMaker maker;
    std::vector<std::string> toppings = {"Pepperoni", "Stefania"};
    maker.createPizza(builder, toppings);
    CustomPizza pizza = builder.getPizza();
    EXPECT_EQ(pizza.getTotalCost(), 3.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}