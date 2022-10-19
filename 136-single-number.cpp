#include "headers.hpp"

class Solution {
public:
  int singleNumber(std::vector<int> &Nums) {
    // XOR magic
    return std::accumulate(Nums.begin(), Nums.end(), 0, std::bit_xor());
  }
};