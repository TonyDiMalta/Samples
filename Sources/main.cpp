#ifdef _DEBUG
    #include <iostream>
    extern void print_type_info_tests();
    extern void print_unique_random_sizes();
    extern void print_any_type_tests();
#endif

int main()
{
#ifdef _DEBUG
    print_type_info_tests();
    system("pause");
    std::cout << '\n';
    print_unique_random_sizes();
    system("pause");
    std::cout << '\n';
    print_any_type_tests();
#endif

    return 0;
}
