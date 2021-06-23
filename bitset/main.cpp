#include <iostream>
#include <type_traits>
#include "bitset.hpp"
#include "bitset_2.hpp"
#include <concepts>

template<typename T, typename ... U>
concept IsAnyOf = (std::same_as<T, U> || ...);

void println(IsAnyOf<int, double, float> auto const ... arguments)
{
	(std::cout << ... << arguments) << '\n';
}

int main(int argc, const char * argv[])
{
//	println(1,2,3,4,5.5f);
	std::cout << bset::log2<1023>::value;
//    return __cpp_concepts >= 201811L;
}
