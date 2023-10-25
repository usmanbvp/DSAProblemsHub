#include <iostream>

// Function to calculate the GCD using the Euclidean algorithm
int calculateGCD(int a, int b) {
    if (b == 0)
        return a;
    return calculateGCD(b, a % b);
}

int main() {
    int num1, num2;

    // Input the two numbers with validation
    std::cout << "Greatest Common Divisor (GCD) Calculator\n";
    std::cout << "Enter the first integer: ";
    if (!(std::cin >> num1)) {
        std::cerr << "Invalid input. Please enter a valid integer.\n";
        return 1; // Exit with an error code
    }
    
    std::cout << "Enter the second integer: ";
    if (!(std::cin >> num2)) {
        std::cerr << "Invalid input. Please enter a valid integer.\n";
        return 1; // Exit with an error code
    }

    // Ensure non-negative numbers for GCD calculation
    num1 = abs(num1);
    num2 = abs(num2);

    // Calculate and display the GCD
    int gcd = calculateGCD(num1, num2);
    std::cout << "The Greatest Common Divisor (GCD) of " << num1 << " and " << num2 << " is " << gcd << std::endl;

    return 0;
}
