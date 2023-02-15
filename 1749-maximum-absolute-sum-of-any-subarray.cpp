#include "headers.hpp"

class Solution {
public:
  int maxAbsoluteSum(const std::vector<int> &Nums) {
    auto Max = 0, Min = 0;
    auto MaxAtIMinus1 = 0, MinAtIMinus1 = 0;
    for (size_t i = 0; i < Nums.size(); i++) {
      MaxAtIMinus1 = std::max(MaxAtIMinus1 + Nums[i], Nums[i]);
      MinAtIMinus1 = std::min(MinAtIMinus1 + Nums[i], Nums[i]);
      Max = std::max(Max, MaxAtIMinus1);
      Min = std::min(Min, MinAtIMinus1);
    }

    return std::max(Max, std::abs(Min));
  }
};
