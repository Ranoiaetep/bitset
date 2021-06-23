#ifndef bitset_hpp
#define bitset_hpp

#include <bitset>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <iostream>

namespace bset
{

template <int x>
 struct log2 { enum { value = 1 + log2<x/2>::value }; };
  
template <> struct log2<1> { enum { value = 1 }; };

template <int x>
 struct pow2 { enum { value = pow2<x - 1>::value * 2 }; };
  
template <> struct pow2<0> { enum { value = 1 }; };

template<std::uint64_t value>
struct bitset
{
    bitset()
    : _bitset(value) {}
    
    std::bitset<log2<std::integral_constant<std::uint64_t, value>::value>::value> _bitset;
    
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
