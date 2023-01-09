#include "headers.hpp"

class Solution {
public:
  int findPeakElement(std::vector<int> &Nums) {
    // Just dealing with edge cases first.
    // That is, the case that the peak is in the left(right) boundary.
    assert(!Nums.empty());
    if (Nums.size() == 1) {
      return 0;
    }
    if (Nums[0] > Nums[1]) {
      return 0;
    }
    if (Nums.back() > Nums[Nums.size() - 2]) {
      return Nums.size() - 1;
    }

    // Now we exclude the first and last elements.
    // Note that because of the excluding, each element in the interval ALWAYS
    // has left and right elements.
    size_t Beg = 1, End = Nums.size() - 1;
    while (Beg < End) {
      auto Mid = Beg + (End - Beg) / 2;
      if (Nums[Mid] > Nums[Mid + 1] && Nums[Mid] > Nums[Mid - 1]) {
        return Mid;
      }

      if (Nums[Mid] < Nums[Mid + 1]) {
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    return Beg;
  }
};
