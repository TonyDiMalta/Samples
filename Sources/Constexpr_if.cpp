#include <cmath>
#include <iostream>
#include <limits>
#include <type_traits>

template<typename T>
constexpr bool is_both()
{
    if constexpr(std::is_integral<T>::value && !std::is_same<bool, T>::value)
    {
        if constexpr(std::numeric_limits<T>::max() < 1000)
        {
            return true;
        }
    }

    return false;
}

template<typename T>
auto print_type_info(const T& t)
{
    if constexpr(is_both<T>())
    {
        return t << 1;
    }
    else if constexpr(std::is_floating_point<T>::value)
    {
        return std::round(t);
    }
    else
    {
        return t;
    }
}

#ifdef _DEBUG
void print_type_info_tests()
{
    std::cout << "Constexpr_if :\n";
    std::cout << print_type_info(5) << '\n';
    std::cout << print_type_info(5ll) << '\n';
    std::cout << print_type_info(1.2) << '\n';
    std::cout << print_type_info(true) << '\n';
    std::cout << print_type_info("hello world") << "\n\n";
}
#endif
