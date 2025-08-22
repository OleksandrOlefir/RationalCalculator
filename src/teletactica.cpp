#include "teletactica.h"

/**
 * @brief Constructs a Rational object with a numerator and a denominator.
 */
Rational::Rational(int numerator, int denominator)
    : m_num(numerator), m_den(denominator) {
    validate();
    reduce();
}

/**
 * @brief Copy constructor.
 */
Rational::Rational(const Rational& other) noexcept
    : m_num(other.m_num), m_den(other.m_den) {}

/**
 * @brief Move constructor.
 */
Rational::Rational(Rational&& other) noexcept
    : m_num(other.m_num), m_den(other.m_den) {
    other.m_num = 0;
    other.m_den = 1;
}

/**
 * @brief Move assignment operator.
 */
Rational& Rational::operator=(Rational&& other) noexcept {
    if (this != &other) {
        m_num = other.m_num;
        m_den = other.m_den;
        other.m_num = 0;
        other.m_den = 1;
    }
    return *this;
}

/**
 * @brief Add two rational numbers.
 */
Rational Rational::operator+(const Rational& other) const noexcept {
    int num = m_num * other.m_den + other.m_num * m_den;
    int den = m_den * other.m_den;
    return Rational(num, den);
}

/**
 * @brief Subtract two rational numbers.
 */
Rational Rational::operator-(const Rational& other) const noexcept {
    int num = m_num * other.m_den - other.m_num * m_den;
    int den = m_den * other.m_den;
    return Rational(num, den);
}

/**
 * @brief Multiply two rational numbers.
 */
Rational Rational::operator*(const Rational& other) const noexcept {
    int num = m_num * other.m_num;
    int den = m_den * other.m_den;
    return Rational(num, den);
}

/**
 * @brief Divide two rational numbers.
 */
Rational Rational::operator/(const Rational& other) const noexcept {
    if (other.m_num == 0) {
        std::cerr << "ERROR: Division by zero!" << std::endl;
        return Rational(0, 1);
    }
    int num = m_num * other.m_den;
    int den = m_den * other.m_num;
    return Rational(num, den);
}

/**
 * @brief Returns the numerator.
 */
int Rational::getNumerator() const noexcept {
    return m_num;
}

/**
 * @brief Returns the denominator.
 */
int Rational::getDenominator() const noexcept {
    return m_den;
}

/**
 * @brief Print the rational number in reduced form.
 */
void Rational::print() const noexcept {
    std::cout << m_num << "/" << m_den << std::endl;
}

/**
 * @brief Validate that the denominator is not zero.
 */
void Rational::validate() const noexcept {
    if (m_den == 0) {
        std::cerr << "ERROR: Denominator must not be zero!" << std::endl;
    }
}

/**
 * @brief Simplify the fraction by dividing by the greatest common divisor.
 */
void Rational::reduce() noexcept {
    int divisor = gcd(m_num, m_den);
    if (divisor != 0) {
        m_num /= divisor;
        m_den /= divisor;
    }

    // Ensure the denominator is positive
    if (m_den < 0) {
        m_num = -m_num;
        m_den = -m_den;
    }
}

/**
 * @brief Calculate the greatest common divisor (GCD) using Euclidean algorithm.
 */
int Rational::gcd(int a, int b) noexcept {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return (a < 0) ? -a : a;
}
