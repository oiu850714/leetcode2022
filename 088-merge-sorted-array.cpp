#include "headers.hpp"

class Solution {
public:
  void merge(std::vector<int> &Nums1, int M, std::vector<int> &Nums2, int N) {
    // The point is that Nums1 already contains empty N slots for elements in
    // Nums2. So the elements can effectively be merged in place of Nums1.

    // The point is merging elements from BACKWARD.
    int MergingPos = Nums1.size() - 1;
    int i = Nums1.size() - 1 - Nums2.size(), j = Nums2.size() - 1;
    while (i >= 0 && j >= 0) {
      if (Nums1[i] > Nums2[j]) {
        std::swap(Nums1[i--], Nums1[MergingPos--]);
      } else {
        std::swap(Nums2[j--], Nums1[MergingPos--]);
      }
    }
    // There is no need to check index i, since if it's >= 0, the remaining
    // elements are "already" in Nums1.
    while (j >= 0) {
      std::swap(Nums2[j--], Nums1[MergingPos--]);
    }
  }
};