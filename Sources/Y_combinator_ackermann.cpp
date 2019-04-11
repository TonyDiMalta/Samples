#include <functional>
#include <iostream>
#include <utility>

namespace std
{
    template<class Fct>
    class y_combinator_result
    {
        Fct fct_;
    public:
        template<class T>
        explicit y_combinator_result(T &&fct): fct_(std::forward<T>(fct)) {}

        template<class ...Args>
        decltype(auto) operator()(Args &&...args)
        {
            return fct_(std::ref(*this), std::forward<Args>(args)...);
        }
    };

    template<class Fct>
    decltype(auto) y_combinator(Fct &&fct)
    {
        return y_combinator_result<std::decay_t<Fct>>(std::forward<Fct>(fct));
    }
} // namespace std

typedef unsigned long long ull;

#ifdef _DEBUG
void print_ackermann_values()
{
    auto ackermann_ = [](auto ackermann, ull m, ull n) -> ull
    {
        if (m == 0)
        {
            return n + 1;
        }

        if (n == 0)
        {
            return ackermann(m - 1, 1);
        }
        
        return ackermann(m - 1, ackermann(m, n - 1));
    };
    auto ackermann = std::y_combinator(std::ref(ackermann_));
    
    // Requires a 10MB stack to solve the case (3, 9) without stack overflow.
    for (ull m = 0; m < 4; ++m)
    {
        for (ull n = 0; n < 10; ++n)
        {
            std::cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << '\n';
        }
    }

    // Requires an even larger stack to solve the case (4, 1) without stack overflow.
    //std::cout << "Ackermann(4, 1) = " << ackermann(4, 1) << "\n\n";
    std::cout << '\n';
}
#endif
