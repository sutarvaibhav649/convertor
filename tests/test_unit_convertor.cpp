#include <gtest/gtest.h>
#include "convertor/unit_convertor.hpp"
#include "category/length_type.hpp"
#include "category/temp_type.hpp"
#include "category/data_type.hpp"

class UnitConvertorTest : public ::testing::Test {
protected:
    convertor::UnitConvertor converter;
};

TEST_F(UnitConvertorTest, LengthConversion) {
    auto res = converter.convertLength(1000.0, category::LengthUnit::METER, category::LengthUnit::KILOMETER);
    ASSERT_TRUE(res.has_value());
    EXPECT_DOUBLE_EQ(*res, 1.0);

    auto inchToKm = converter.convertLength(1.0, category::LengthUnit::INCH, category::LengthUnit::KILOMETER);
    ASSERT_TRUE(inchToKm.has_value());
    EXPECT_NEAR(*inchToKm, 0.0000254, 1e-7);
}

TEST_F(UnitConvertorTest, TemperatureConversion) {
    auto fToC = converter.convertTemp(32.0, category::TempUnit::FAHRENHEIT, category::TempUnit::CELSIUS);
    ASSERT_TRUE(fToC.has_value());
    EXPECT_NEAR(*fToC, 0.0, 1e-4);

    auto cToK = converter.convertTemp(0.0, category::TempUnit::CELSIUS, category::TempUnit::KELVIN);
    ASSERT_TRUE(cToK.has_value());
    EXPECT_NEAR(*cToK, 273.15, 1e-4);
}

TEST_F(UnitConvertorTest, DataConversion) {
    auto tbToGb = converter.convertData(1.0, category::DataUnit::TERABYTE, category::DataUnit::GIGABYTE);
    ASSERT_TRUE(tbToGb.has_value());
    EXPECT_DOUBLE_EQ(*tbToGb, 1024.0);
}