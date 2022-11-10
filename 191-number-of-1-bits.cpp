#include "headers.hpp"

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int NibbleIndex[] = {
        0, // 0000
        1, // 0001
        1, // 0010
        2, // 0011
        1, // 0100
        2, // 0101
        2, // 0110
        3, // 0111
        1, // 1000
        2, // 1001
        2, // 1010
        3, // 1011
        2, // 1100
        3, // 1101
        3, // 1110
        4, // 1111
    };
    return NibbleIndex[n & 0xf] + NibbleIndex[(n >> 4) & 0xf] +
           NibbleIndex[(n >> 8) & 0xf] + NibbleIndex[(n >> 12) & 0xf] +
           NibbleIndex[(n >> 16) & 0xf] + NibbleIndex[(n >> 20) & 0xf] +
           NibbleIndex[(n >> 24) & 0xf] + NibbleIndex[(n >> 28) & 0xf];
  }
};