#include "headers.hpp"

class Solution {
public:
  int maxSubArray(std::vector<int> &Nums) {
    // Refer to Kadane's Algorithm.

    // Base case
    auto MaxSubEndingAtI = Nums.front(), Ret = MaxSubEndingAtI;
    // DP, or Kadane's Algorithm.
    for (size_t i = 1; i < Nums.size(); i++) {
      MaxSubEndingAtI = std::max(MaxSubEndingAtI + Nums[i], Nums[i]);
      Ret = std::max(Ret, MaxSubEndingAtI);
    }
    return Ret;
  }
};