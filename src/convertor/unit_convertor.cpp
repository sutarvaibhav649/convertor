#include "convertor/unit_convertor.hpp"

namespace convertor {

    UnitConvertor::UnitConvertor() {
        initializeMap();
    }

    void UnitConvertor::initializeMap() {
        // -------------------------------------------------------------
        // Length Multipliers (Base Unit: METER)
        // -------------------------------------------------------------
        lengthToMeterMap = {
            { category::LengthUnit::METER,      1.0 },
            { category::LengthUnit::KILOMETER,  1000.0 },
            { category::LengthUnit::CENTIMETER, 0.01 },
            { category::LengthUnit::MILLIMETER, 0.001 },
            { category::LengthUnit::MILE,       1609.344 },
            { category::LengthUnit::FOOT,       0.3048 },
            { category::LengthUnit::INCH,       0.0254 }
        };

        // -------------------------------------------------------------
        // Weight Multipliers (Base Unit: GRAM)
        // -------------------------------------------------------------
        weightToGramMap = {
            { category::WeightUnit::GRAM,      1.0 },
            { category::WeightUnit::KILOGRAM,  1000.0 },
            { category::WeightUnit::MILLIGRAM, 0.001 },
            { category::WeightUnit::POUND,     453.59237 },
            { category::WeightUnit::OUNCE,     28.349523125 }
        };

        // -------------------------------------------------------------
        // Data Multipliers (Base Unit: BYTE)
        // -------------------------------------------------------------
        dataToByteMap = {
            { category::DataUnit::BYTE,     1.0 },
            { category::DataUnit::KILOBYTE, 1024.0 },
            { category::DataUnit::MEGABYTE, 1024.0 * 1024.0 },
            { category::DataUnit::GIGABYTE, 1024.0 * 1024.0 * 1024.0 },
            { category::DataUnit::TERABYTE, 1024.0 * 1024.0 * 1024.0 * 1024.0 }
        };

        // -------------------------------------------------------------
        // Temperature Functions (Base Unit: KELVIN)
        // Using std::function + Lambdas to handle non-linear offsets
        // -------------------------------------------------------------
        tempToKelvinMap = {
            { category::TempUnit::KELVIN,     [](double k) { return k; } },
            { category::TempUnit::CELSIUS,    [](double c) { return c + 273.15; } },
            { category::TempUnit::FAHRENHEIT, [](double f) { return (f - 32.0) * (5.0 / 9.0) + 273.15; } }
        };

        kelvinToTempMap = {
            { category::TempUnit::KELVIN,     [](double k) { return k; } },
            { category::TempUnit::CELSIUS,    [](double k) { return k - 273.15; } },
            { category::TempUnit::FAHRENHEIT, [](double k) { return (k - 273.15) * (9.0 / 5.0) + 32.0; } }
        };
    }

    std::optional<double> UnitConvertor::convertLength(double value, category::LengthUnit from, category::LengthUnit to) const {
        auto fromIt = lengthToMeterMap.find(from);
        auto toIt = lengthToMeterMap.find(to);

        if (fromIt == lengthToMeterMap.end() || toIt == lengthToMeterMap.end()) {
            return std::nullopt;
        }

        
        double valueInMeters = value * fromIt->second;
        return valueInMeters / toIt->second;
    }

    std::optional<double> UnitConvertor::convertWeight(double value, category::WeightUnit from, category::WeightUnit to) const {
        auto fromIt = weightToGramMap.find(from);
        auto toIt = weightToGramMap.find(to);

        if (fromIt == weightToGramMap.end() || toIt == weightToGramMap.end()) {
            return std::nullopt;
        }

        double valueInGrams = value * fromIt->second;
        return valueInGrams / toIt->second;
    }

    std::optional<double> UnitConvertor::convertData(double value, category::DataUnit from, category::DataUnit to) const {
        auto fromIt = dataToByteMap.find(from);
        auto toIt = dataToByteMap.find(to);

        if (fromIt == dataToByteMap.end() || toIt == dataToByteMap.end()) {
            return std::nullopt;
        }

        double valueInBytes = value * fromIt->second;
        return valueInBytes / toIt->second;
    }

    std::optional<double> UnitConvertor::convertTemp(double value, category::TempUnit from, category::TempUnit to) const {
        auto toKelvinIt = tempToKelvinMap.find(from);
        auto fromKelvinIt = kelvinToTempMap.find(to);

        if (toKelvinIt == tempToKelvinMap.end() || fromKelvinIt == kelvinToTempMap.end()) {
            return std::nullopt;
        }

        double kelvin = toKelvinIt->second(value);

       
        return fromKelvinIt->second(kelvin);
    }

} // namespace converter