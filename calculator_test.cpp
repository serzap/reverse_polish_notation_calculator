#include <gtest/gtest.h>
#include "calculator.hpp"
#include <iostream>

TEST(CalculatorTest, TestOperatorPlus)
{
    auto result = calculateExpression("2 2 +");
    EXPECT_DOUBLE_EQ(4.0,result) << result;
}

TEST(CalculatorTest, TestOperatorMinus)
{
    auto result = calculateExpression("6 3 -");
    EXPECT_DOUBLE_EQ(3.0,result);
}

TEST(CalculatorTest, TestOperatorMultiply)
{
    auto result = calculateExpression("6 3 *");
    EXPECT_DOUBLE_EQ(18.0,result);
}

TEST(CalculatorTest, TestOperatorDivide)
{
    auto result = calculateExpression("10 2 /");
    EXPECT_DOUBLE_EQ(5.0,result);
}

TEST(CalculatorTest, TestManyOpeartions)
{
    auto result = calculateExpression("5 3 + 7 * 2 /");
    EXPECT_DOUBLE_EQ(28.0, result);
}

