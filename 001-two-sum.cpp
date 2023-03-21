#include "headers.hpp"

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &Nums, int Target) {
    std::unordered_map<int, int> NumIdx;
    for (int i = 0; i < Nums.size(); i++) {
      auto Num1 = Nums[i], Num2 = Target - Num1;
      if (NumIdx.count(Num2)) {
        return {i, NumIdx.at(Num2)};
      }
      NumIdx[Num1] = i;
    }
    // Impossible by the assumption.
    return {-1, -1};
  }
};
