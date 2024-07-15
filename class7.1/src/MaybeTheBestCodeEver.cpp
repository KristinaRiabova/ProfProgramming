#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> 
#include <cstddef> 

class Rectangle {
public:
    Rectangle(double width, double height) : width(width), height(height), area(width * height) {}

    double getWidth() const { return width; }
    double getHeight() const { return height; }
    double getArea() const { return area; }

    bool canFitInside(const Rectangle& other) const {
        return width <= other.getWidth() && height <= other.getHeight();
    }

private:
    double width;
    double height;
    double area;
};

class RectangleManager {
public:
    void addRectangle(const Rectangle& rectangle) {
        rectangles.push_back(rectangle);
        updateBiggestArea(rectangle.getArea());
        updateSmallestArea(rectangle.getArea());
    }

    const std::vector<Rectangle>& getRectangles() const {
        return rectangles;
    }

    double getBiggestArea() const {
        return biggestArea;
    }

    double getSmallestArea() const {
        return smallestArea;
    }

    double getTotalArea() const {
        double totalArea = 0;
        for (const auto& rectangle : rectangles) {
            totalArea += rectangle.getArea();
        }
        return totalArea;
    }

private:
    std::vector<Rectangle> rectangles;
    double biggestArea = 0;
    double smallestArea = std::numeric_limits<double>::max();

    void updateBiggestArea(double area) {
        if (area > biggestArea) {
            biggestArea = area;
        }
    }

    void updateSmallestArea(double area) {
        if (area < smallestArea) {
            smallestArea = area;
        }
    }
};

void printRectangleFits(const RectangleManager& manager) {
    const auto& rectangles = manager.getRectangles();
    for (size_t i = 0; i < rectangles.size(); ++i) {
        for (size_t j = 0; j < rectangles.size(); ++j) {
            if (i != j && rectangles[i].canFitInside(rectangles[j])) {
                std::cout << "Rectangle " << i + 1 << " can be placed inside Rectangle " << j + 1 << std::endl;
            }
        }
    }
}

void printBiggestSides(const RectangleManager& manager) {
    const auto& rectangles = manager.getRectangles();
    for (size_t i = 0; i < rectangles.size(); ++i) {
        double biggestSide = std::max(rectangles[i].getWidth(), rectangles[i].getHeight());
        std::cout << "The biggest side of rectangle " << i + 1 << ": " << biggestSide << std::endl;
    }
}

void runProgram() {
    RectangleManager manager;
    for (int i = 0; i < 5; ++i) {
        double width, height;
        std::cout << "Enter rectangle " << i + 1 << ":\n";
        std::cin >> width >> height;
        manager.addRectangle(Rectangle(width, height));
    }

    printRectangleFits(manager);

    std::cout << "The biggest area: " << manager.getBiggestArea() << std::endl;
    std::cout << "The smallest area: " << manager.getSmallestArea() << std::endl;

    printBiggestSides(manager);

    std::cout << "Total area of rectangles: " << manager.getTotalArea() << std::endl;
}

int main() {
    runProgram();
    return 0;
}