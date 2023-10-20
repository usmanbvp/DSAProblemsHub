def sieve_of_eratosthenes(n):
    primes = [True] * (n + 1)
    primes[0], primes[1] = False, False

    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1

    return [num for num in range(2, n + 1) if primes[num]]

def prime_factors(n):
    factors = []
    primes = sieve_of_eratosthenes(n)

    for prime in primes:
        while n % prime == 0:
            factors.append(prime)
            n //= prime

    if n > 1:
        factors.append(n)

    return factors

# Example usage
number = 84
factors = prime_factors(number)
print(f"The prime factors of {number} are: {factors}")
