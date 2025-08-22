#include "gtest/gtest.h"
#include "teletactica.h"

/**
 * @brief Tests for Rational number construction and validation.
 */

// Valid input – no exceptions should occur
TEST(RationalTest, ValidInputDoesNotThrow) {
    EXPECT_NO_THROW({
        Rational r(2, 3);
        EXPECT_EQ(r.getNumerator(), 2);
        EXPECT_EQ(r.getDenominator(), 3);
    });
}

// Negative denominator – should normalize to positive
TEST(RationalTest, NegativeDenominatorNormalization) {
    Rational r(5, -3);
    EXPECT_EQ(r.getNumerator(), -5);
    EXPECT_EQ(r.getDenominator(), 3);
}

// Double negative – should normalize to positive
TEST(RationalTest, DoubleNegativeNormalization) {
    Rational r(-4, -8);
    EXPECT_EQ(r.getNumerator(), 1);
    EXPECT_EQ(r.getDenominator(), 2);
}

// Zero numerator – should simplify to 0/1
TEST(RationalTest, ZeroNumeratorSimplification) {
    Rational r(0, 10);
    EXPECT_EQ(r.getNumerator(), 0);
    EXPECT_EQ(r.getDenominator(), 1);
}

/**
 * @brief Tests for Rational arithmetic operations.
 */

// Addition test
TEST(RationalTest, AdditionWorksCorrectly) {
    Rational r1(1, 4);
    Rational r2(1, 4);
    Rational result = r1 + r2;

    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

// Subtraction test
TEST(RationalTest, SubtractionWorksCorrectly) {
    Rational r1(3, 4);
    Rational r2(1, 4);
    Rational result = r1 - r2;

    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

// Multiplication test
TEST(RationalTest, MultiplicationWorksCorrectly) {
    Rational r1(2, 3);
    Rational r2(3, 4);
    Rational result = r1 * r2;

    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);
}

// Division test
TEST(RationalTest, DivisionWorksCorrectly) {
    Rational r1(3, 4);
    Rational r2(2, 3);
    Rational result = r1 / r2;

    EXPECT_EQ(result.getNumerator(), 9);
    EXPECT_EQ(result.getDenominator(), 8);
}

/**
 * @brief Tests to confirm no exceptions are thrown for valid/edge inputs.
 */

// All operations should not throw
TEST(RationalTest, AllOperationsNoThrow) {
    Rational r1(1, 2);
    Rational r2(2, 3);

    EXPECT_NO_THROW({
        Rational sum = r1 + r2;
        Rational diff = r1 - r2;
        Rational mult = r1 * r2;
        Rational div = r1 / r2;

        (void)sum;
        (void)diff;
        (void)mult;
        (void)div;
    });
}

// Division by zero – fallback case, not exception
TEST(RationalTest, DivisionByZeroInputNoThrow) {
    EXPECT_NO_THROW({
        Rational r1(1, 2);
        Rational r2(0, 0); // denominator fallback to 1
        Rational result = r1 / r2;
        (void)result;
    });
}
