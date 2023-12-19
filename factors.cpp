#include "factors.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

std::vector<std::pair<long long, long long>> factorize(long long number);

void factorize_file(const std::string& file_path);

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

std::vector<std::pair<long long, long long>> factorize(long long number) {
    std::vector<std::pair<long long, long long>> factors;

    while (number > 1) {
        long long factor = pollards_rho(number);
        while (number % factor == 0) {
            factors.emplace_back(factor, number / factor);
            number /= factor;
        }
    }

    return factors;
}

void factorize_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "Failed to open the file: " << file_path << std::endl;
        return;
    }

    long long number;
    while (file >> number) {
        std::vector<std::pair<long long, long long>> factors = factorize(number);
        for (const auto& factor : factors) {
            std::cout << number << "=" << factor.first << "*" << factor.second << std::endl;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    factorize_file(argv[1]);

    return 0;
}
