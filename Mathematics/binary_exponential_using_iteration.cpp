/**
 * @file
 * @brief C++ Program to find Binary Exponent Iteratively and Recursively.
 *
 * Calculate \f$a^b\f$ in \f$O(\log(b))\f$ by converting \f$b\f$ to a
 * binary number. Binary exponentiation is also known as exponentiation by
 * squaring.
 * @note This is a far better approach compared to naive method which
 * provide \f$O(b)\f$ operations.
 *
 * Example:
 * </br>10 in base 2 is 1010.
 * \f{eqnarray*}{
 * 2^{10_d} &=& 2^{1010_b} = 2^8 * 2^2\\
 * 2^1 &=& 2\\
 * 2^2 &=& (2^1)^2 = 2^2 = 4\\
 * 2^4 &=& (2^2)^2 = 4^2 = 16\\
 * 2^8 &=& (2^4)^2 = 16^2 = 256\\
 * \f}
 * Hence to calculate 2^10 we only need to multiply \f$2^8\f$ and \f$2^2\f$
 * skipping \f$2^1\f$ and \f$2^4\f$.
 */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// Iterative function to calculate exponent in O(log(n)) using binary exponent.
int binExpo_alt(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

/// Main function
int main() {
    int a, b;
    /// Give two numbers a, b
    cin >> a >> b;
    if (a == 0 && b == 0) {
        cout << "error occured" << std::endl;
    } else if (b < 0) {
        cout << "Exponent must be in positive value!!" << std::endl;
    } else {
         int resIterated = binExpo_alt(a, b);

        cout << resIterated << std::endl;
    }
}