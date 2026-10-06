#include <gtest/gtest.h>
#include "category/category_type.hpp"
#include "category/unit_parser.hpp"

TEST(UnitParserTest, StringToCategory) {
    EXPECT_EQ(category::stringToCategory("LENGTH"), category::CategoryType::LENGTH);
    EXPECT_EQ(category::stringToCategory("LEN"), category::CategoryType::LENGTH);
    EXPECT_EQ(category::stringToCategory("TEMP"), category::CategoryType::TEMPERATURE);
    EXPECT_EQ(category::stringToCategory("INVALID"), category::CategoryType::UNKNOWN);
}

TEST(UnitParserTest, StringToLengthUnit) {
    EXPECT_EQ(category::stringToLengthUnit("KM"), category::LengthUnit::KILOMETER);
    EXPECT_EQ(category::stringToLengthUnit("METER"), category::LengthUnit::METER);
    EXPECT_EQ(category::stringToLengthUnit("FT"), category::LengthUnit::FOOT);
    EXPECT_EQ(category::stringToLengthUnit("ABC"), category::LengthUnit::UNKNOWN);
}