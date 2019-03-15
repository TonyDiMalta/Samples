#include <algorithm>
#include <future>
#include <iostream>
#include <iterator>
#include <random>
#include <set>

std::set<int> make_sorted_random(const size_t num_elems, const int min_val, const int max_val)
{
    std::set<int> retval;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min_val, max_val);

    std::generate_n(
        std::inserter(
            retval,
            retval.end()
        ),
        num_elems,
        [&]() {
            return dis(gen);
        }
    );

    return retval;
}

#ifdef _DEBUG
void print_unique_random_sizes()
{
    std::cout << "Future_async :" << '\n';

    auto f1 = std::async(std::launch::async, make_sorted_random, 1000000, 0, 1000000);
    auto f2 = std::async(std::launch::async, make_sorted_random, 1000000, 0, 1000000);
    auto f3 = std::async(std::launch::deferred, make_sorted_random, 1000000, 0, 1000000);
    
    std::cout <<
        f1.get().size() << '\n' <<
        f2.get().size() << '\n' <<
        f3.get().size() << "\n\n";
}
#endif
