#include "headers.hpp"

class Solution {
public:
  int searchInsert(std::vector<int> &Nums, int Target) {
    int Beg = 0, End = Nums.size();
    while (Beg < End) {
      auto Mid = Beg + (End - Beg) / 2;
      if (Nums[Mid] == Target) {
        return Mid;
      } else if (Nums[Mid] < Target) {
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    return Beg;
  }
};
