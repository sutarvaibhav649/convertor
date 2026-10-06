#pragma once

#include <string>

namespace category
{
    enum class CategoryType {
        UNKNOWN,
        LENGTH,
        WEIGHT,
        DATA,
        TEMPERATURE
    };

    CategoryType stringToCategory(const std::string& str);
    std::string categoryToString(CategoryType cat); // Pass by value or const ref
} // namespace category