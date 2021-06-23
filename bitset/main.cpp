#include <iostream>
#include <type_traits>
#include "bitset.hpp"

int main(int argc, const char * argv[])
{
    std::cout << bset::bitset<10>() + bset::bitset<10>();
    return 0;
}
