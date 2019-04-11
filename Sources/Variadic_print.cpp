#include <iostream>
#include <sstream>
#include <vector>

template <typename... T>
std::vector<std::string> print(const T& ... t)
{
    std::stringstream ss;
    return {
        (
            ss.str(""),
            ss << t,
            ss.str()
        )...
    };
}

#ifdef _DEBUG
void print_any_type_tests()
{
    std::cout << "Variadic_print :\n";

    const auto to_print = print("Hello", "World", 5.4f, 1, 2.2f);

    for (const auto& s : to_print)
    {
        std::cout << s << '\n';
    }

    std::cout << '\n';
}
#endif
