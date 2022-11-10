#include "headers.hpp"

using RangePairTy = std::vector<std::pair<int, int>>;
using RangeStrTy = std::vector<std::string>;

class Solution {
public:
  std::vector<std::string> summaryRanges(std::vector<int> &Nums) {
    RangePairTy Ranges;
    if (Nums.empty()) {
      return {};
    }

    auto LeftBound = Nums[0], RightBound = Nums[0];
    for (int i = 1; i < Nums.size(); i++) {
      if (Nums[i] > RightBound + 1) {
        Ranges.push_back({LeftBound, RightBound});
        LeftBound = RightBound = Nums[i];
      } else {
        RightBound = Nums[i];
      }
    }
    // Push last range.
    Ranges.push_back({LeftBound, RightBound});

    return convertRange_(Ranges);
  }

private:
  // Just copied/modified from 163.
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
