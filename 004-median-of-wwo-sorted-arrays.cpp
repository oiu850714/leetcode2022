#include "headers.hpp"

class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &Nums1,
                                std::vector<int> &Nums2) {
    // Just try to make sure that the first vector is smaller than the second.
    if (Nums1.size() > Nums2.size()) {
      std::swap(Nums1, Nums2);
    }

    // Try to exclude some special cases first.
    // One vector maybe empty.
    // We assume the other is NOT empty and return the median of the other.
    if (Nums1.empty()) {
      return medianOfNonEmptySortedArray(Nums2);
    }

    // At this point, both vectors are non-empty.
    // Now we try to find two bound for Nums1 and Nums2 such that the number of
    // elements beside the left of these two bounds is equal to the number
    // below:
    // If total elements is even, we keep the elements beside the left of the
    // bounds as half of the total. Otherwise, we take one more elements.
    // Either cases, (Nums1.size() + Nums2.size() + 1) / 2 correctly represents
    // this quantity.
    const int ElementsOfFirstPortion = (Nums1.size() + Nums2.size() + 1) / 2;

    int Beg = 0, End = Nums1.size();
    while (Beg != End) {
      auto Bound1 = Beg + (End - Beg) / 2;
      // Note that since Num1.size() <= Nums2.size(), Bound2 is always
      // nonnegative.
      auto Bound2 = ElementsOfFirstPortion - Bound1;
      auto [Bound1Left, Bound1Right, Bound2Left, Bound2Right] =
          elementsBesideBounds(Nums1, Nums2, Bound1, Bound2);
      if (Bound1Left <= Bound2Right && Bound2Left <= Bound1Right) {
        // We have found the appropriate bound(s).
        return findMedian(Nums1, Nums2, Bound1, Bound2);
      } else if (Bound1Left > Bound2Right) {
        // The biggest element in the first portion of Nums1 is too big.
        End = Bound1;
      } else {
        // The biggest element in the first portion of Nums2 is too big.
        Beg = Bound1 + 1;
      }
    }
    return findMedian(Nums1, Nums2, Beg, ElementsOfFirstPortion - Beg);
  }

private:
  // Assume the two bounds are correct.
  double findMedian(const std::vector<int> &Nums1,
                    const std::vector<int> &Nums2, int Bound1, int Bound2) {
    auto [FirstLeft, FirstRight, SecondLeft, SecondRight] =
        elementsBesideBounds(Nums1, Nums2, Bound1, Bound2);
    if ((Nums1.size() + Nums2.size()) % 2) {
      // Odd number of elements total.
      // The median is the minimum of the elements in the left of the two
      // bounds.
      return std::max(FirstLeft, SecondLeft);
    } else {
      // Even number of elements total.
      // The median is the maximum of the elements in the left of the two
      // bounds + the minimum of the elements in the right of the two, and
      // divided by 2.
      return (double)(std::max(FirstLeft, SecondLeft) +
                      std::min(FirstRight, SecondRight)) /
             2;
    }
  }

  double medianOfNonEmptySortedArray(const std::vector<int> &Nums) {
    auto Size = Nums.size();
    return Size % 2 ? Nums[Size / 2]
                    : (double)(Nums[(Size - 1) / 2] + Nums[Size / 2]) / 2;
  }

  // If the bound is in the first element, we set the
  // bound-left element to be INT_MIN, to denote the "vacuous" case that the
  // biggest (non-existent) element beside the left of the bound is smaller than
  // the smallest element beside the right of the bound.
  // Similar to the case that the bound is after the last element.
  std::tuple<int, int, int, int>
  elementsBesideBounds(const std::vector<int> &Nums1,
                       const std::vector<int> &Nums2, int Bound1, int Bound2) {
    auto Bound1Left = Bound1 - 1 >= 0 ? Nums1[Bound1 - 1] : INT_MIN;
    auto Bound1Right = Bound1 < Nums1.size() ? Nums1[Bound1] : INT_MAX;
    auto Bound2Left = Bound2 - 1 >= 0 ? Nums2[Bound2 - 1] : INT_MIN;
    auto Bound2Right = Bound2 < Nums2.size() ? Nums2[Bound2] : INT_MAX;
    return {Bound1Left, Bound1Right, Bound2Left, Bound2Right};
  }
};