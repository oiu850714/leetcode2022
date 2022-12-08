#include "headers.hpp"

class Solution {
public:
  int minSubArrayLen(int Target, std::vector<int> &Nums) {
    // PrefixSum[i] stores sum of Nums[0, i).
    std::vector<int> PrefixSum(Nums.size() + 1);
    std::partial_sum(Nums.begin(), Nums.end(), PrefixSum.begin() + 1);

    // The whole array sum < Target, then any subarray sum < Target.
    if (PrefixSum.back() < Target) {
      return 0;
    }

    // The whole array is itself a valid subarray, so we can set initial Max to
    // the array size.
    int Max = Nums.size();

    for (int i = 0; i < Nums.size(); i++) {
      auto Wanted = Target + PrefixSum[i];
      auto Idx =
          std::lower_bound(PrefixSum.begin() + i, PrefixSum.end(), Wanted);
      if (Idx == PrefixSum.end()) {
        // Sum of Nums[i, End) < Target.
        continue;
      }
      Max = std::min<int>(Max, Idx - (PrefixSum.begin() + i));
    }
    return Max;
  }
};
