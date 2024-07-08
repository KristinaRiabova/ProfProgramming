#include "UnitTests.hpp"
#include <cmath>
#include <gtest/gtest.h>
#include <algorithm>  

class Triangle {
public:
    Triangle(double a, double b, double c) : side1(a), side2(b), side3(c) {
        if (!isValidTriangle()) {
            throw std::invalid_argument("Invalid side lengths for a triangle.");
        }
    }

    double area() const {
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

private:
    double side1, side2, side3;

    bool isValidTriangle() const {
        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
            return false;
        }
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }
};

void test_triangle_area_valid() {
    // Valid test cases for triangle area
    Triangle triangle1(3, 4, 5);
    ASSERT_EQ(triangle1.area(), 6.0);

    Triangle triangle2(7, 8, 9);
    ASSERT_NEAR(triangle2.area(), 26.832815729997478, 1e-6);

    Triangle triangle3(10, 10, 10);
    ASSERT_NEAR(triangle3.area(), 43.3012701892, 1e-6);
}

void test_triangle_area_invalid() {
    // Invalid test cases for triangle area
    ASSERT_THROW(Triangle(-3, 4, 5), std::invalid_argument);
    ASSERT_THROW(Triangle(3, -4, 5), std::invalid_argument);
    ASSERT_THROW(Triangle(3, 4, -5), std::invalid_argument);
    ASSERT_THROW(Triangle(1, 1, 2), std::invalid_argument);
    ASSERT_THROW(Triangle(1, 2, 1), std::invalid_argument);
    ASSERT_THROW(Triangle(2, 1, 1), std::invalid_argument);
}

class Color {
public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {
        if (!isValidColor()) {
            throw std::invalid_argument("Invalid RGB values.");
        }
    }

    void generateMagicColor() {
        red = std::clamp(red / 2 - 1, 0, 255);
        green = std::clamp(green * 2 - 2, 0, 255);
        // Blue component remains unchanged
    }

    int getRed() const { return red; }
    int getGreen() const { return green; }
    int getBlue() const { return blue; }

private:
    int red, green, blue;

    bool isValidColor() const {
        return (red >= 0 && red <= 255) &&
               (green >= 0 && green <= 255) &&
               (blue >= 0 && blue <= 255);
    }
};

void test_magic_color_generation_valid() {
    // Valid test cases for magic color generation
    Color color1(255, 128, 64);
    color1.generateMagicColor();
    ASSERT_EQ(color1.getRed(), 126);
    ASSERT_EQ(color1.getGreen(), 254);
    ASSERT_EQ(color1.getBlue(), 64);

    Color color2(100, 150, 200);
    color2.generateMagicColor();
    ASSERT_EQ(color2.getRed(), 49);
    ASSERT_EQ(color2.getGreen(), 298); // This will be clamped to 255
    ASSERT_EQ(color2.getBlue(), 200);
}

void test_magic_color_generation_invalid() {
    // Invalid test cases for magic color generation
    ASSERT_THROW(Color(-1, 128, 64), std::invalid_argument);
    ASSERT_THROW(Color(256, 128, 64), std::invalid_argument);
    ASSERT_THROW(Color(255, -1, 64), std::invalid_argument);
    ASSERT_THROW(Color(255, 128, 256), std::invalid_argument);
}

int main() {
    UnitTests tests;
    tests.addTest("Test Valid Triangle Area", test_triangle_area_valid);
    tests.addTest("Test Invalid Triangle Area", test_triangle_area_invalid);
    tests.addTest("Test Valid Magic Color Generation", test_magic_color_generation_valid);
    tests.addTest("Test Invalid Magic Color Generation", test_magic_color_generation_invalid);
    tests.run();

    return 0;
}
