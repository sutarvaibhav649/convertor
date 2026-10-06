#include "category/category_type.hpp"

namespace category
{
    CategoryType stringToCategory(const std::string& str){
        if(str == "LENGTH" || str == "LEN") return CategoryType::LENGTH; 
        else if(str == "WEIGHT" || str == "WT") return CategoryType::WEIGHT;
        else if(str == "TEMPERATURE" || str == "TEMP") return CategoryType::TEMPERATURE;
        else if(str == "DATA") return CategoryType::DATA;
        else return CategoryType::UNKNOWN;
    }

    std::string categoryToString(CategoryType& type){
        if(type == CategoryType::LENGTH) return "LENGTH";
        else if(type == CategoryType::WEIGHT) return "WEIGHT"; 
        else if(type == CategoryType::TEMPERATURE) return "TEMPERATURE";
        else if(type == CategoryType::DATA) return "DATA"; 
        else return "UNKNOWN";      
    }
} // namespace category
