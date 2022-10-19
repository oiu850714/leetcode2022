#include "headers.hpp"

class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &Cost) {
    auto Top = Cost.size();
    // one more element to recored the cost at the top
    std::vector<int> DPTable(Top + 1);

    // We can freely stand at index 0 and index 1.
    DPTable[0] = 0;
    DPTable[1] = 0;
    for (size_t i = 2; i < Top + 1; i++) {
      // Either stand at index i - 2, pay the cost for index i - 2, and advance
      // 2 steps to index i, or stand at index i - 1, pay the cost for index i -
      // 1, and advance 1 step to index i.

      DPTable[i] =
          std::min(DPTable[i - 2] + Cost[i - 2], DPTable[i - 1] + Cost[i - 1]);
    }
    return DPTable[Top];
  }
};