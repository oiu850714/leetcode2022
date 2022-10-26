#include "headers.hpp"

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &Nums, int Target) {
    // By assumption, Nums.size() >= 2.
    for (size_t firstIdx = 0; firstIdx < Nums.size() - 1; firstIdx++) {
      auto Remain = Target - Nums[firstIdx];
      auto LowerBound =
          std::lower_bound(Nums.begin() + firstIdx + 1, Nums.end(), Remain);
      if (LowerBound != Nums.end() && *LowerBound == Remain) {
        // The conversion is due to the return type.
        return {(int)firstIdx + 1, (int)(LowerBound - Nums.begin() + 1)};
      }
    }
    throw; // By assumption, this is impossible.
  }
};