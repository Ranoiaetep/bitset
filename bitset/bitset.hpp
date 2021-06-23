#ifndef bitset_hpp
#define bitset_hpp

#include <bitset>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <iostream>
#include "helper.hpp"

namespace bset
{
template<std::uint64_t value>
struct bitset
{
    bitset()
    : _bitset(value) {}
    
    std::bitset<value
		? log2<value>::value + 1
		: 1> _bitset;
    
    explicit constexpr operator std::uint64_t() const { return value; }
};

template<std::uint64_t value>
inline std::ostream& operator<<(std::ostream& os, bitset<value> _bitset)
{
    return os << _bitset._bitset;
}

template<std::uint64_t lhs, std::uint64_t rhs>
constexpr auto operator+ (bitset<lhs>, bitset<rhs>)
{
    return bitset<lhs + rhs>();
}

}

#endif /* bitset_hpp */
