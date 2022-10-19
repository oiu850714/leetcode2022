#include "headers.hpp"

class Solution {
public:
  int climbStairs(int n) {
    // tweak table size, and ignore the 0th element
    std::vector<int> DPTable(std::max(3, n + 1));
    // two base cases
    DPTable[1] = 1;
    DPTable[2] = 2;
    for (int i = 3; i < n + 1; i++) {
      DPTable[i] = DPTable[i - 1] + DPTable[i - 2];
    }
    return DPTable[n];
  }
};