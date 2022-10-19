#include "headers.hpp"

class Solution {
public:
  int findMin(std::vector<int> &Nums) {
    // If Nums only has one element or Nums is actually sorted.
    if (Nums.size() == 1 || Nums.front() < Nums.back()) {
      return Nums.front();
    }
    // Now Nums has at least two element and is rotated.
    // Note that if an element is bigger than the FIRST element of Nums, then
    // the element is in the first portion of Nums. Else the element is in the
    // second portion of Nums.
    auto B = Nums.begin(), E = Nums.end(); // [B, E)
    while (E - B >
           10) { // Honestly I hate the boundary check, especially when the
                 // problem is not a conventional binary search problem.
      // So just leave several elements at the end and do a quick scan on them.
      auto M = B + (E - B) / 2;
      if (Nums.front() < *M) {
        // M is still in the first sorted portion
        B = M + 1;
      } else {
        // M is in the second sorted portion.
        // But "we still need M to be in the searched range", since it may point
        // to the pivot element.
        E = M + 1;
      }
    }
    return *std::min_element(B, E);
  }
};