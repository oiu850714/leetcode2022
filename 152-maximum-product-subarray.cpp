#include "headers.hpp"

class Solution {
  // Related: 053.
public:
  int maxProduct(std::vector<int> &Nums) {
    auto Ret = Nums.front(), MaxEndingAtI = Ret, MinEndingAtI = Ret;
    for (size_t i = 1; i < Nums.size(); i++) {
      // The condition is modified from 053.
      std::initializer_list<int> Candidates{MaxEndingAtI * Nums[i],
                                            MinEndingAtI * Nums[i], Nums[i]};
      MaxEndingAtI = std::max(Candidates);
      MinEndingAtI = std::min(Candidates);
      Ret = std::max(Ret, MaxEndingAtI);
    }
    return Ret;
  }
};