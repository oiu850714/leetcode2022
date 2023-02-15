#include "headers.hpp"

class Solution {
public:
  int maxProfit(const std::vector<int> &Prices) {
    int Ret = 0;
    for (size_t i = 1; i < Prices.size(); i++) {
      // If we can profit from buying today + selling tomorrow, we do it.
      // Otherwise don't do anything.
      Ret += std::max(0, Prices[i] - Prices[i - 1]);
    }
    return Ret;
  }
};
