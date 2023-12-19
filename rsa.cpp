#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

long long pollards_rho(long long n) {
    if (n == 1) return 1;

    if (n % 2 == 0) return 2;

    long long x = rand() % (n - 2) + 2;
    long long y = x;
    long long c = rand() % (n - 1) + 1;
    long long d = 1;

    auto gcd = [](long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    };

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = gcd(std::abs(x - y), n);
    }

    return d;
}

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

void factorize_rsa(long long n) {
    long long factor = pollards_rho(n);

    while (!is_prime(factor)) {
        factor = pollards_rho(n);
    }

    long long other_factor = n / factor;

    std::cout << n << "=" << factor << "*" << other_factor << std::endl;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number>" << std::endl;
        return 1;
    }

    srand(time(NULL));  // Initialize random seed

    long long n = std::atoll(argv[1]);
    factorize_rsa(n);

    return 0;
}
