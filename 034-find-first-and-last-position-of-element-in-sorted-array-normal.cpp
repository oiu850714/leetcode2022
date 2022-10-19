#include "headers.hpp"

class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &Nums, int Target) {
    // Input may be empty.
    if (Nums.empty()) {
      return {-1, -1};
    }

    // lower_bound
    auto Beg = Nums.begin(), End = Nums.end();
    while (Beg != End) {
      auto Mid = Beg + (End - Beg) / 2;
      if (*Mid < Target) { // Note the "<" relation
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    const auto LowerBound = Beg;

    // upper_bound
    Beg = Nums.begin(), End = Nums.end();
    while (Beg != End) {
      auto Mid = Beg + (End - Beg) / 2;
      if (*Mid <= Target) { // Note the "<=" relation
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    // Now Beg points to the first element NOT equal to Target.
    // So we subtract it from 1 to make it point to the last Target, if exists.
    const auto UpperBound = Beg - 1;

    if (LowerBound == Nums.end() || *LowerBound != Target) {
      return {-1, -1};
    } else {
      return {(int)(LowerBound - Nums.begin()),
              (int)(UpperBound - Nums.begin())};
    }
  }
};