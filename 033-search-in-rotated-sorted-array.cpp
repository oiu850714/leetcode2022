#include "headers.hpp"

class Solution {
public:
  int search(const std::vector<int> &Nums, int Target) {
    auto Beg = Nums.begin(), End = Nums.end(); // [Beg, End)
    while (Beg < End) { // the interval has at least one element
      auto Mid = Beg + (End - Beg) / 2;
      if (*Mid == Target) {
        return Mid - Nums.begin();
      }

      if (*Nums.begin() < *Mid) { // Mid is still in the left sorted portion of
                                  // the rotated array.
        if (*Mid < Target) {
          // If Nums[Mid] < Target, then since Mid is in the left portion,
          // Nums[Beg, Mid) are all smaller than Target, so move Beg.
          Beg = Mid + 1;
        } else {
          // Else, if Nums[Mid] > Target, then we check the value of Nums[Beg].
          if (*Beg > Target) {
            // If Nums[Beg] > Target, then Nums[Beg, Mid) are all bigger than
            // Target, so we also move Beg.
            Beg = Mid + 1;
          } else {
            // If Nums[Beg] < Target, then Target can only be in Nums[Beg, Mid),
            // since Nums[Mid, pivot) are all greater than or equal to
            // Nums[Mid], which is greater than Target.
            // And Nums[pivot, End) are all smaller than Nums[Beg], which is
            // smaller than Target.
            End = Mid;
          }
        }
      } else { // Mid is in the right sorted portion of the rotated array.
        if (*Mid > Target) {
          // If Nums[Mid] > Target, then since Mid is in the right portion,
          // Nums[Mid + 1, End) are all bigger than Target, so move End.
          End = Mid;
        } else {
          // Else, if Nums[Mid] < Target, then we check the value of Nums[End -
          // 1].
          if (*(End - 1) < Target) {
            // If Nums[End - 1] < Target, then Nums[Mid + 1, End) are all
            // smaller than Target, so we also move End.
            End = Mid;
          } else {
            // If Nums[End - 1] > Target, then Target can only be in Nums[Mid +
            // 1, End), since Nums[Beg, pivot) are all greater than or equal to
            // Nums[End - 1], which is greater than Target.
            // And Nums[pivot, Mid) are all smaller than Nums[Mid], which is
            // smaller than Target.
            Beg = Mid + 1;
          }
        }
      }
    }
    return -1;
  }
};