#ifndef helper_hpp
#define helper_hpp

#include <utility>
#include <iostream>

namespace bset {

template <std::uint64_t x, size_t _bit_length>
struct log2_imp
{
	static constexpr size_t value = x & (1ull << _bit_length) ? _bit_length
	: log2_imp<x, _bit_length - 1>::value;
};

template <std::uint64_t x>
struct log2_imp<x, 0>
{
	static constexpr std::uint64_t value = 0;
};

template <size_t _bit_length>
struct log2_imp<0, _bit_length>
{
	static constexpr std::uint64_t value = _bit_length + 1;
};

template <std::uint64_t x>
struct log2
{
	static constexpr std::uint64_t value = log2_imp<x, sizeof(std::uint64_t) * __CHAR_BIT__ - 1>::value;
};

template <int x>
struct pow2 { enum { value = pow2<x - 1>::value * 2 }; };

template <> struct pow2<0> { enum { value = 1 }; };

template <typename Ints, Ints... ints, Ints new_int>
auto append_integer_sequence(std::integer_sequence<Ints, ints...>) { return std::integer_sequence<Ints, ints..., new_int>(); }
}

#endif /* helper_hpp */
