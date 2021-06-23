#ifndef bitset_2_hpp
#define bitset_2_hpp

#include <utility>
#include "helper.hpp"

namespace bset2 {
template<std::uint64_t Value>
struct bitset
{
	constexpr auto impl(std::size_t size)
	{
		if constexpr (!(Value / 2))
		{
			
		}
	}
	
	constexpr auto operator()() const
	{
		
	}
};
}

#endif /* bitset_2_hpp */
