#include "calc/calculator.h"
#include <gtest/gtest.h>

class TestFoo : public ::testing::Test
{
protected:
    void SetUp() {}
    void TearDown() {}
};

TEST(CalculatorTest, Addition) {
    Calculator calculator("1 + 2 + 3");
    double result = calculator.calculate();
    EXPECT_EQ(result, 6);
}

TEST(CalculatorTest, Subtraction) {
    Calculator calculator("10 - 5 - 3");
    double result = calculator.calculate();
    EXPECT_EQ(result, 2);
}

TEST(CalculatorTest, Multiplication) {
    Calculator calculator("2 * 3 * 4");
    double result = calculator.calculate();
    EXPECT_EQ(result, 24);
}

TEST(CalculatorTest, Division) {
    Calculator calculator("20 / 5 / 2");
    double result = calculator.calculate();
    EXPECT_EQ(result, 2);
}

TEST(CalculatorTest, Power) {
    Calculator calculator("2 ^ 3 ^ 2");
    double result = calculator.calculate();
    EXPECT_EQ(result, 512);
}

TEST(CalculatorTest, Parentheses) {
    Calculator calculator("2 * (3 + 4)");
    double result = calculator.calculate();
    EXPECT_EQ(result, 14);
}

TEST(CalculatorTest, NegativeNumber) {
    Calculator calculator("-2 * 3");
    double result = calculator.calculate();
    EXPECT_EQ(result, -6);
}

TEST(CalculatorTest, DecimalNumber) {
    Calculator calculator("0.5 * 2.5");
    double result = calculator.calculate();
    EXPECT_EQ(result, 1.25);
}

TEST(CalculatorTest, ComplexExpression) {
    Calculator calculator("0.5 * 2.5 - (2 * 3)^2");
    double result = calculator.calculate();
    EXPECT_EQ(result, -34.75);
}


int main(int argc, const char * argv[]) {
    ::testing::InitGoogleTest(&argc, (char**)argv);
    return RUN_ALL_TESTS();
}
