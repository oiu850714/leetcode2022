#include "headers.hpp"

class Solution {
public:
  int threeSumClosest(std::vector<int> &Nums, int Target) {
    std::sort(Nums.begin(), Nums.end());
    int Ret = Nums[0] + Nums[1] + Nums[2];
    // By assumption, Nums.size() >= 3.
    for (int First = 0; First < Nums.size() - 2; First++) {
      for (int Second = First + 1, Third = Nums.size() - 1; Second < Third;) {
        const auto Result = Nums[First] + Nums[Second] + Nums[Third];
        if (Result == Target) {
          return Target;
        } else if (Result > Target) {
          Third--;
        } else {
          Second++;
        }
        if (std::abs(Target - Result) < std::abs(Target - Ret)) {
          Ret = Result;
        }
      }
    }
    return Ret;
  }
};