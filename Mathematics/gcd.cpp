#include <iostream>

int calcGCD(int n, int m) {
    if (n == 0) {
        return m;
    } else if (m == 0) {
        return n;
    } else if (n > m) {
        return calcGCD(n % m, m);
    } else {
        return calcGCD(n, m % n);
    }
}

int main() {
    int n, m;

    std::cout << "Enter two integers: ";
    std::cin >> n >> m;

    int gcd = calcGCD(n, m);

    std::cout << "GCD of " << n << " and " << m << " is " << gcd << std::endl;

    return 0;
}
