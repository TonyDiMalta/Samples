#include <stdexcept>

[[nodiscard]] constexpr int add(const int lhs, const int rhs) noexcept
{
    return lhs + rhs;
}

[[nodiscard]] constexpr int mul(const int lhs, const int rhs) noexcept
{
    return lhs * rhs;
}

[[nodiscard]] constexpr int safe_div(const int numerator, const int denominator)
{
    if (denominator == 0)
    {
        throw std::domain_error("Attempted to divide by zero.");
    }
    return (numerator / denominator);
}
