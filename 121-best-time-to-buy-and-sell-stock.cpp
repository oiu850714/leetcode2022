#include "headers.hpp"

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int MaxProfit = 0;
    for (auto BuyDay = prices.begin(), SellDay = prices.begin();
         SellDay != prices.end(); SellDay++) {
      MaxProfit = std::max(MaxProfit, *SellDay - *BuyDay);
      if (*SellDay < *BuyDay) {
        BuyDay = SellDay;
      }
    }
    return MaxProfit;
  }
};