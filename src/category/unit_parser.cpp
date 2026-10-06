#include "category/unit_parser.hpp"

namespace category
{
    LengthUnit stringToLengthUnit(const std::string& str){
        if(str == "METER" || str == "MT") return LengthUnit::METER;
        else if(str == "KILOMETER" || str == "KM") return LengthUnit::KILOMETER;
        else if(str == "MILE" || str == "MI") return LengthUnit::MILE;
        else if(str == "INCH" || str == "IN") return LengthUnit::INCH;
        else if(str == "FOOT" || str == "FT") return LengthUnit::FOOT;
        else if(str == "CENTIMETER" || str == "CM") return LengthUnit::CENTIMETER;
        else if(str == "MILLIMETER" || str == "MM") return LengthUnit::MILLIMETER;
        else return LengthUnit::UNKNOWN;
    }

    std::string lengthUnitToString(LengthUnit unit){
        switch (unit)
        {
            case LengthUnit::CENTIMETER:    return "CENTIMETER"; break;
            case LengthUnit::FOOT:          return "FOOT"; break;
            case LengthUnit::INCH:          return "INCH"; break;
            case LengthUnit::KILOMETER:     return "KILOMETER"; break;
            case LengthUnit::METER:         return "METER"; break;
            case LengthUnit::MILE:          return "MILE"; break;
            case LengthUnit::MILLIMETER:    return "MILLIMETER"; break;
            default: return "UNKNOWN"; break;
        }
    }

    WeightUnit stringToWeightUnit(const std::string& str){
        if(str == "GRAM" || str == "GM") return WeightUnit::GRAM;
        else if(str == "KILOGRAM" || str == "KG") return WeightUnit::KILOGRAM;
        else if(str == "MILLIGRAM" || str == "MG") return WeightUnit::MILLIGRAM;
        else if(str == "OUNCE" || str == "OU") return WeightUnit::OUNCE;
        else if(str == "POUNDS" || str == "PD") return WeightUnit::POUND;
        else return WeightUnit::UNKNOWN;
    }

    std::string weightUnitToString(WeightUnit unit){
        switch(unit){
            case WeightUnit::GRAM:      return "GRAM"; break;
            case WeightUnit::KILOGRAM:  return "KILOGRAM"; break;
            case WeightUnit::MILLIGRAM: return "MILLIGRAM"; break;
            case WeightUnit::OUNCE:     return "OUNCE"; break;
            case WeightUnit::POUND:     return "POUND"; break;
            default:                    return "UNKNOWN"; break;
        }
    }

    TempUnit stringToTempUnit(const std::string& str){
        if(str == "KELVIN" || str == "K") return TempUnit::KELVIN;
        else if(str == "CELSIUS" || str == "C") return TempUnit::CELSIUS;
        else if(str == "FAHRENHEIT" || str == "F") return TempUnit::FAHRENHEIT;
        else return TempUnit::UNKNOWN;
        
    }

    std::string tempUnitToString(TempUnit unit){
        switch(unit){
            case TempUnit::CELSIUS:     return "CELSIUS"; break;
            case TempUnit::FAHRENHEIT:  return "FAHRENHEIT"; break;
            case TempUnit::KELVIN:      return "KELVIN"; break;
            default:                    return "UNKNOWN"; break;
        }
    }

    DataUnit stringToDataUnit(const std::string& str){
        if(str == "BYTE" || str == "B") return DataUnit::BYTE;
        else if(str == "KILOBYTE" || str == "KB") return DataUnit::KILOBYTE;
        else if(str == "GIGABYTE" || str == "GB") return DataUnit::GIGABYTE;
        else if(str == "MEGABYTE" || str == "MB") return DataUnit::MEGABYTE;
        else if(str == "TERABYTE" || str == "TB") return DataUnit::TERABYTE;
        else return DataUnit::UNKNOWN;
    }

    std::string dataUnitToString(DataUnit unit){
        switch (unit)
        {
            case DataUnit::BYTE:        return "BYTE"; break;
            case DataUnit::GIGABYTE:    return "GIGABYTE"; break;
            case DataUnit::KILOBYTE:    return "KILOBYTE"; break;
            case DataUnit::MEGABYTE:    return "MEGABYTE"; break;
            case DataUnit::TERABYTE:    return "TERABYTE"; break;
            default:                    return "UNKNOWN"; break;
        }
    }
} // namespace category
