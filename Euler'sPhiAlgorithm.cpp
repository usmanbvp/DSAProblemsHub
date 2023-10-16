#include <iostream>
#include <cmath>

int phi(int n) {
    int result = n; // Initialize result as n

    // Check for all prime factors of n and subtract their multiples from result
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) { // p is a prime factor of n
            while (n % p == 0) { // Remove all multiples of p from n
                n /= p;
            }
            result -= result / p;
        }
    }
    // If n has a prime factor greater than sqrt(n), then add its contribution
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;
    int phi_n = phi(n);
    std::cout << "phi(" << n << ") = " << phi_n << std::endl;
    return 0;
}
