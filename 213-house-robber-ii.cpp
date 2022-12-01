#include "headers.hpp"

class Solution {
public:
  int rob(std::vector<int> &Nums) {
    if (Nums.size() == 1) {
      return Nums[0];
    }
    if (Nums.size() == 2) {
      return std::max(Nums[0], Nums[1]);
    }
    return std::max(skipFirstHouse_(Nums), skipLastHouse_(Nums));
  }

private:
  int skipFirstHouse_(const std::vector<int> &Nums) {
    return sol198ButUsingInterval(Nums, 1, Nums.size());
  }

  int skipLastHouse_(const std::vector<int> &Nums) {
    return sol198ButUsingInterval(Nums, 0, Nums.size() - 1);
  }

  // Modified from 198.
  // Assume End - Beg >= 2.
  int sol198ButUsingInterval(const std::vector<int> &Nums, int Beg, int End) {
    auto DPEntry1 = Nums[Beg], DPEntry2 = std::max(Nums[Beg], Nums[Beg + 1]);
    for (int i = Beg + 2; i < End; i++) {
      auto NewValue = std::max(DPEntry2, DPEntry1 + Nums[i]);
      DPEntry1 = DPEntry2;
      DPEntry2 = NewValue;
    }
    return DPEntry2;
  }
};
