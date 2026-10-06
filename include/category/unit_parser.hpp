#pragma once

#include "category/length_type.hpp"
#include "category/weight_type.hpp"
#include "category/temp_type.hpp"
#include "category/data_type.hpp"

#include <string>

namespace category
{
    LengthUnit stringToLengthUnit(const std::string& str);
    std::string lengthUnitToString(LengthUnit unit);
    
    WeightUnit stringToWeightUnit(const std::string& str);
    std::string weightUnitToString(WeightUnit unit);

    TempUnit stringToTempUnit(const std::string& str);
    std::string tempUnitToString(TempUnit unit);

    DataUnit stringToDataUnit(const std::string& str);
    std::string dataUnitToString(DataUnit unit);
} // namespace category
