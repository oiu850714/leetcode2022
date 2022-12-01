#include "headers.hpp"

class Solution {
public:
  int minCost(std::vector<std::vector<int>> &Costs) {
    assert(Costs.size() && Costs[0].size() == 3);
    const int Red = 0, Blue = 1, Green = 2;
    int RedMin = Costs[0][Red], BlueMin = Costs[0][Blue],
        GreenMin = Costs[0][Green];
    for (int i = 1; i < Costs.size(); i++) {
      std::tie(RedMin, BlueMin, GreenMin) = std::tuple{
          Costs[i][Red] + std::min(BlueMin, GreenMin),
          Costs[i][Blue] + std::min(RedMin, GreenMin),
          Costs[i][Green] + std::min(RedMin, BlueMin),
      };
    }
    return std::min({RedMin, BlueMin, GreenMin});
  }
};
