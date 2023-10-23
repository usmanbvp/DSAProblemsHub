#include <iostream>
using namespace std;

// Function to print a decimal number as a binary number
void printBinary(int num) {
    // Iterate through the bits of the number (assuming a 32-bit integer)
    for (int i = 31; i >= 0; --i) {
        // Shift the number to the right by 'i' bits and bitwise AND with 1
        // This extracts the i-th bit from the right
        int bit = (num >> i) & 1;
        
        // Print the bit
        cout << bit;
    }
    cout << endl;
}

int main() {
    int decimalNumber;

    // Input: Ask the user to enter a decimal number
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    // Check for negative numbers
    if (decimalNumber < 0) {
        cout << "Negative numbers are not supported in this example." << endl;
    } else {
        // Call the function to print the binary representation
        cout << "Binary representation: ";
        printBinary(decimalNumber);
    }

    return 0;
}
