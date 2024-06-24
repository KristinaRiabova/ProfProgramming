#include <iostream>
#include <memory>
#include "ModernCalculators.hpp"
#include "LegacyCalculator.hpp"
#include "MegaAdapter.hpp" // Include MegaAdapter.hpp

void printResults(const std::unique_ptr<BaseMegaCalculator>& calculator) {
    std::cout << "Current price: " << calculator->getPrice() << std::endl;
    std::cout << "Current minimal value: " << calculator->getMinimalValue() << std::endl;
    std::cout << "Current report: " << calculator->getReport() << std::endl;
}

int main() {
    std::unique_ptr<BaseMegaCalculator> calculator = std::make_unique<MyCoolCalculator>(6.0, 12.1, 3.2);
    printResults(calculator);

    calculator = std::make_unique<ConstantCalculator>();
    printResults(calculator);

    calculator = std::make_unique<MegaAdapter>(std::make_unique<LegacyCalculator>(1.34, 5.4));
    printResults(calculator);

    return 0;
}
