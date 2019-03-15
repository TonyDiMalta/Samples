#include <cmath>
#include <iostream>

constexpr unsigned int Fibonacci(const unsigned int i)
{
    if (i < 2) return i;

    const auto sqrt_5 = std::sqrt(5);

    return static_cast<unsigned int>((std::pow(1 + sqrt_5, i) - std::pow(1 - sqrt_5, i)) / (std::pow(2, i) * sqrt_5));
}
