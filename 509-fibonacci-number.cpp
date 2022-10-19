#include "headers.hpp"

class Solution {
public:
  int fib(int n) {
    // tweak table size to at least 2 to prevent overflow.
    std::vector<int> DPTable(std::max(2, n + 1));
    DPTable[0] = 0;
    DPTable[1] = 1;
    for (size_t i = 2; i < n + 1; i++) {
      DPTable[i] = DPTable[i - 1] + DPTable[i - 2];
    }
    return DPTable[n];
  }
};