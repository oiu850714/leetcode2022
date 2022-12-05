#include "headers.hpp"

class Solution {
public:
  int numberOfArithmeticSlices(std::vector<int> &Nums) {
    if (Nums.size() < 3) {
      return 0;
    }
    int Ret = Nums[2] - Nums[1] == Nums[1] - Nums[0];
    int CountEndAtCurr = Ret;
    for (int Curr = 3; Curr < Nums.size(); Curr++) {
      auto NewCount = 0;
      if (Nums[Curr] - Nums[Curr - 1] == Nums[Curr - 1] - Nums[Curr - 2]) {
        NewCount +=
            // all subarrays end at Curr - 1 + Nums[Curr]
            CountEndAtCurr
            // and the NEWLY FORMED subarray,
            // {Nums[Curr - 2], Nums[Curr - 1], Nums[Curr]}.
            + 1;
        // Note that {Nums[Curr - 2], Nums[Curr - 1]} is NOT a subarray and at
        // Curr - 1, since it consist only two elements.
      }
      Ret += NewCount;
      CountEndAtCurr = NewCount;
    }

    return Ret;
  }
};
