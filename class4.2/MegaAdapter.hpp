#pragma once

#include <string>
#include <sstream>
#include <memory>
#include "LegacyCalculator.hpp"
#include "ModernCalculators.hpp"

class MegaAdapter : public BaseMegaCalculator {
public:
    MegaAdapter(std::unique_ptr<LegacyCalculator> legacyCalculator)
        : legacyCalculator(std::move(legacyCalculator)) {}

    double getPrice() const override {
        return legacyCalculator->calculatePricePart1() + legacyCalculator->calculatePricePart2();
    }

    double getMinimalValue() const override {
        return legacyCalculator->getOurTheMostAndMinimalValue();
    }

    std::string getReport() const override {
        std::ostringstream oss;
        oss << legacyCalculator->getSomeDocumentRepresentation();
        return oss.str();
    }

private:
    std::unique_ptr<LegacyCalculator> legacyCalculator;
};
