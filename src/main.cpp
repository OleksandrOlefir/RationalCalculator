#include <iostream>
#include "teletactica.h"

/**
 * @brief Get integer input from the user with a prompt.
 */
int getInput(const std::string& message) {
    int value{};
    std::cout << message;
    while (!(std::cin >> value)) {
        std::cerr << "Invalid input. Please enter a valid integer: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return value;
}

/**
 * @brief Display available operations to the user.
 */
void displayMenu() {
    std::cout << "\nSelect operation:\n"
              << "1 - Addition (+)\n"
              << "2 - Subtraction (-)\n"
              << "3 - Multiplication (*)\n"
              << "4 - Division (/)\n"
              << "Choice: ";
}

/**
 * @brief Entry point of the program.
 */
int main() {
    // Input for first rational number
    int num1 = getInput("Enter numerator for number 1: ");
    int den1 = getInput("Enter denominator for number 1: ");

    // Input for second rational number
    int num2 = getInput("Enter numerator for number 2: ");
    int den2 = getInput("Enter denominator for number 2: ");

    // Create rational number objects
    Rational r1(num1, den1);
    Rational r2(num2, den2);

    // Ask user for operation
    displayMenu();
    int choice{};
    std::cin >> choice;

    Rational result(0, 1);  // Default result

    switch (choice) {
        case 1:
            result = r1 + r2;
            std::cout << "Result: ";
            result.print();
            break;
        case 2:
            result = r1 - r2;
            std::cout << "Result: ";
            result.print();
            break;
        case 3:
            result = r1 * r2;
            std::cout << "Result: ";
            result.print();
            break;
        case 4:
            result = r1 / r2;
            std::cout << "Result: ";
            result.print();
            break;
        default:
            std::cerr << "Invalid operation selected.\n";
            break;
    }

    return 0;
}
