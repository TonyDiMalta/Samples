#include <algorithm>

int my_min(int x, int y, int z)
{
    return std::min(std::min(x, y), z);
}

int my_min2(int x, int y, int z)
{
    return std::min( {x, y, z} );
}

template<typename T>
T variadic_min(T && t)
{
	return std::forward<T>(t);
}

template<typename T1, typename T2, typename... Ts>
typename std::common_type<T1, T2, Ts...>::type
variadic_min(T1 && val1, T2 && val2, Ts && ... vs)
{
	return variadic_min(val1 < val2 ? std::forward<T1>(val1) : std::forward<T2>(val2), std::forward<Ts>(vs)...);
}

int my_min3(int x, int y, int z)
{
    return variadic_min(x, y, z);
}

template<typename T>
T variadic_min2(T && t)
{
	return std::forward<T>(t);
}

template<typename T1, typename... Ts>
typename std::common_type<T1, Ts...>::type
variadic_min2(T1 && val1, Ts && ... vs)
{
	return std::min(val1, variadic_min2(std::forward<Ts>(vs)...));
}

int my_min4(int x, int y, int z)
{
    return variadic_min2(x, y, z);
}
