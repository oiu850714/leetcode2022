#include "headers.hpp"

class Solution {
public:
  int singleNumber(const std::vector<int> &Nums) {
    std::array<int, 32> BitCount{};
    for (auto Num : Nums) {
      for (auto i = 0; i < 32; i++) {
        BitCount[i] += (Num & (1 << i)) != 0;
      }
    }
    int Ret = 0;
    for (int i = 0; i < 32; i++) {
      if (BitCount[i] % 3) {
        Ret |= (1 << i);
      }
    }
    return Ret;
  }
};
