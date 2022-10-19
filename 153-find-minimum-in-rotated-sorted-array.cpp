#include "headers.hpp"

class Solution {
public:
  int findMin(std::vector<int> &Nums) {
    // If Nums is actually sorted.
    if (Nums.front() < Nums.back()) {
      return Nums.front();
    }

    int Ret =
        INT_MAX; // Since Nums is non-empty, the loop below will execute at
                 // least once, hence Ret will be updated at least once.
    auto B = Nums.begin(), E = Nums.end(); // [B, E)
    while (B < E) {                        // Still has TWO element.
      auto M = B + (E - B) / 2;
      Ret = std::min(Ret, *M);

      if (Nums.front() < *M) {
        // M is still in the first sorted portion
        B = M + 1;
      } else {
        // M is in the second sorted portion.
        E = M;
      }
    }
    return Ret;
  }
};
