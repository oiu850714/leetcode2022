#include "headers.hpp"

class Solution {
public:
  int pivotIndex(std::vector<int> &Nums) {
    std::vector<int> PrefixSum(Nums.size());
    std::partial_sum(Nums.begin(), Nums.end(), PrefixSum.begin());

    for (auto PivotIdx = 0u; PivotIdx < Nums.size(); PivotIdx++) {
      auto LeftSum = (PivotIdx == 0u) ? 0 : PrefixSum[PivotIdx - 1];
      auto RightSum = (PivotIdx == Nums.size() - 1)
                          ? 0
                          : PrefixSum.back() - PrefixSum[PivotIdx];
      if (LeftSum == RightSum) {
        return PivotIdx;
      }
    }
    return -1;
  }
};