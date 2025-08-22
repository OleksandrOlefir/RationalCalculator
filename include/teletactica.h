#pragma once

#include <iostream>

/**
 * @brief Represents a rational number (fraction) with integer numerator and denominator.
 * 
 * This class supports basic arithmetic operations such as addition, subtraction,
 * multiplication, and division. It ensures that the denominator is always non-zero
 * and automatically reduces the fraction to its simplest form.
 */
class Rational {
public:
    /**
     * @brief Construct a Rational number from two integers (numerator and denominator).
     * @param numerator Integer numerator.
     * @param denominator Integer denominator (must not be zero).
     */
    Rational(int numerator, int denominator);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Rational() noexcept = default;

    /**
     * @brief Copy constructor.
     */
    Rational(const Rational& value) noexcept;

    /**
     * @brief Move constructor.
     */
    Rational(Rational&& value) noexcept;

    /**
     * @brief Move assignment operator.
     */
    Rational& operator=(Rational&& value) noexcept;

    /**
     * @brief Copy assignment operator (deleted for simplicity and safety).
     */
    Rational& operator=(const Rational& value) = delete;

    /**
     * @brief Adds two rational numbers.
     */
    Rational operator+(const Rational& value) const noexcept;

    /**
     * @brief Subtracts two rational numbers.
     */
    Rational operator-(const Rational& value) const noexcept;

    /**
     * @brief Multiplies two rational numbers.
     */
    Rational operator*(const Rational& value) const noexcept;

    /**
     * @brief Divides two rational numbers.
     */
    Rational operator/(const Rational& value) const noexcept;

    /**
     * @brief Get the numerator.
     */
    int getNumerator() const noexcept;

    /**
     * @brief Get the denominator.
     */
    int getDenominator() const noexcept;

    /**
     * @brief Print the rational number.
     */
    void print() const noexcept;

private:
    int m_num;  ///< Numerator
    int m_den;  ///< Denominator

    /**
     * @brief Reduce the fraction to its simplest form.
     */
    void reduce() noexcept;

    /**
     * @brief Calculate the greatest common divisor (GCD).
     */
    static int gcd(int a, int b) noexcept;

    /**
     * @brief Validate the state of the rational number (denominator must not be zero).
     */
    void validate() const noexcept;
};
