#include "headers.hpp"

class Solution {
public:
  long long zeroFilledSubarray(const std::vector<int> &Nums) {
    auto equal0 = [](auto Val) { return Val == 0; };
    long long Result = 0;
    for (auto B = std::find_if(Nums.begin(), Nums.end(), equal0);
         B != Nums.end();) {
      auto E = std::find_if_not(B, Nums.end(), equal0);
      auto Len = E - B;
      // += #subarrays for this interval, [B, E), of 0s.
      Result += (Len + 1) * Len / 2;
      B = std::find_if(E, Nums.end(), equal0);
    }
    return Result;
  }
};
