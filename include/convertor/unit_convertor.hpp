#pragma once

#include "category/length_type.hpp"
#include "category/weight_type.hpp"
#include "category/temp_type.hpp"
#include "category/data_type.hpp"

#include <functional>
#include <unordered_map>
#include <optional>

namespace convertor
{
    class UnitConvertor
    {
        private:
            std::unordered_map<category::LengthUnit,double> lengthToMeterMap;
            std::unordered_map<category::DataUnit, double> dataToByteMap;
            std::unordered_map<category::WeightUnit, double> weightToGramMap;

            std::unordered_map<category::TempUnit,std::function<double(double)>> tempToKelvinMap;
            std::unordered_map<category::TempUnit,std::function<double(double)>> kelvinToTempMap;
            
            void initializeMap();

        public:
            UnitConvertor();
            std::optional<double> convertLength(double value, category::LengthUnit from, category::LengthUnit to) const;
            std::optional<double> convertWeight(double value, category::WeightUnit from, category::WeightUnit to) const;
            std::optional<double> convertData(double value, category::DataUnit from, category::DataUnit to) const;
            std::optional<double> convertTemp(double value, category::TempUnit from, category::TempUnit to) const;
    };
} // namespace convertor
