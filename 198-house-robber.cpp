#include "headers.hpp"

class Solution {
public:
  int rob(std::vector<int> &Nums) {
    // This is the maximum-independent-set problem for "path-graph".
    // Some textbook for this problem: Algorithms Illuminated Part3 Ch16.1.
    if (Nums.size() == 1) {
      return Nums[0];
    }
    if (Nums.size() == 2) {
      return std::max(Nums[0], Nums[1]);
    }
    auto DPEntry1 = Nums[0], DPEntry2 = std::max(Nums[0], Nums[1]);
    for (int i = 2; i < Nums.size(); ++i) {
      auto NewValue = std::max(DPEntry2, DPEntry1 + Nums[i]);
      DPEntry1 = DPEntry2;
      DPEntry2 = NewValue;
    }
    return DPEntry2;
  }
};