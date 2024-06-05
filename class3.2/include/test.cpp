#include "UnitTests.hpp"
#include <cmath>
#include <gtest/gtest.h> 

class Triangle {
public:
    Triangle(double a, double b, double c) : side1(a), side2(b), side3(c) {}

    double area() const {
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

private:
    double side1, side2, side3;
};

void test_triangle_area() {
    // Test cases for triangle area
    Triangle triangle1(3, 4, 5);
    ASSERT_EQ(triangle1.area(), 6.0);

    Triangle triangle2(7, 8, 9);
    ASSERT_EQ(triangle2.area(), 26.832815729997478);

    Triangle triangle3(10, 10, 10);
    ASSERT_EQ(triangle3.area(), 43.3012701892);
}

class Color {
public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    void generateMagicColor() {
        red = red / 2 - 1;
        green = green * 2 - 2;
        // Blue component remains unchanged
    }

    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }

private:
    int red, green, blue;
};

void test_magic_color_generation() {
    // Test cases for magic color generation
    Color color1(255, 128, 64);
    color1.generateMagicColor();
    ASSERT_EQ(color1.getRed(), 126);
    ASSERT_EQ(color1.getGreen(), 254);
    ASSERT_EQ(color1.getBlue(), 64);

    Color color2(0, 255, 0);
    color2.generateMagicColor();
    ASSERT_EQ(color2.getRed(), -1);
    ASSERT_EQ(color2.getGreen(), 508);
    ASSERT_EQ(color2.getBlue(), 0);

    Color color3(100, 150, 200);
    color3.generateMagicColor();
    ASSERT_EQ(color3.getRed(), 49);
    ASSERT_EQ(color3.getGreen(), 298);
    ASSERT_EQ(color3.getBlue(), 200);
}

int main() {
    UnitTests tests;
    tests.addTest("Test Triangle Area", test_triangle_area);
    tests.addTest("Test Magic Color Generation", test_magic_color_generation);
    tests.run();

    return 0;
}
