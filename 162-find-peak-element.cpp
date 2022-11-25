#include "headers.hpp"

class Solution {
public:
  int findPeakElement(std::vector<int> &Nums) {
    int Beg = 0, End = Nums.size();
    while (Beg < End) {
      // If the interval has only one element, that element is a peak of the
      // original array.
      if (End - Beg == 1) {
        return Beg;
      }
      // Two elements case is similar, except that we return the index of the
      // maximum.
      if (End - Beg == 2) {
        return Nums[Beg] > Nums[Beg + 1] ? Beg : Beg + 1;
      }

      // Else, the interval has at least 3 elements, and it's guaranteed that
      // there is at least one element in the left and right of the middle
      // element, respectively.
      int Mid = Beg + (End - Beg) / 2;
      if (Nums[Mid] > Nums[Mid - 1] && Nums[Mid] > Nums[Mid + 1]) {
        return Mid;
      } else if (Nums[Mid] < Nums[Mid - 1]) {
        End = Mid;
      } else {
        Beg = Mid + 1;
      }
    }

    // It can be shown that, with the assumption of the problem:
    // 1. Adjacent elements are distinct.
    // 2. Leftmost/rightmost element only check right/left element.
    // There will always exist a peak element.
    return -1;
  }
};
