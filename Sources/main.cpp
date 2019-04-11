#ifdef _DEBUG
#include <iostream>
#include <limits>

extern void print_type_info_tests();
extern void print_unique_random_sizes();
extern void print_any_type_tests();

void flush(std::istream& in)
{
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    in.clear();
}

void pause()
{
    std::cout << "Press [Enter] to continue...";
    flush(std::cin);
}

template <class Fct>
void call_functions_with_pause(Fct && fct)
{
    fct();
    pause();
    std::cout << '\n';
}

template <class Fct, class... Fcts>
void call_functions_with_pause(Fct && fct, Fcts && ... fcts)
{
    call_functions_with_pause(fct);
    call_functions_with_pause(std::forward<Fcts>(fcts)...);
}
#endif

int main()
{
#ifdef _DEBUG
    call_functions_with_pause(
        print_type_info_tests,
        print_unique_random_sizes,
        print_any_type_tests
    );
#endif

    return 0;
}
