#include "headers.hpp"

class Solution {
public:
  int maxProfit(std::vector<int> &Prices) {
    int MaxProfit = 0;
    for (auto MinPriceBeforeSell = Prices[0], SellDay = 1;
         SellDay < Prices.size(); SellDay++) {
      MaxProfit = std::max(MaxProfit, Prices[SellDay] - MinPriceBeforeSell);
      MinPriceBeforeSell = std::min(MinPriceBeforeSell, Prices[SellDay]);
    }
    return MaxProfit;
  }
};
