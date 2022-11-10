#include "headers.hpp"

using RangePairTy = std::vector<std::pair<int, int>>;
using RangeStrTy = std::vector<std::string>;

class Solution {
public:
  RangeStrTy findMissingRanges(std::vector<int> &Nums, int Lower, int Upper) {
    if (Nums.size() == 0) {
      return convertRange_({{Lower, Upper}});
    }

    RangePairTy Ranges;
    if (Lower < Nums[0]) {
      Ranges.push_back({Lower, Nums[0] - 1});
    }

    for (int i = 0; i < Nums.size() - 1; i++) {
      if (Nums[i] + 1 < Nums[i + 1]) {
        Ranges.push_back({Nums[i] + 1, Nums[i + 1] - 1});
      }
    }

    if (Nums.back() < Upper) {
      Ranges.push_back({Nums.back() + 1, Upper});
    }
    return convertRange_(Ranges);
  }

private:
  RangeStrTy convertRange_(const RangePairTy &Ranges) {
    RangeStrTy Ret;
    for (auto &[Beg, End] : Ranges) {
      if (Beg == End) {
        Ret.push_back(std::to_string(Beg));
      } else {
        Ret.push_back(std::to_string(Beg) + "->" + std::to_string(End));
      }
    }
    return Ret;
  }
};
