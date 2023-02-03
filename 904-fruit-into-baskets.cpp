#include "headers.hpp"

class Solution {
public:
  int totalFruit(std::vector<int> &Fruits) {
    std::unordered_map<int, int> IntervalFruitCount;
    int Max = 0;
    for (int L = 0, R = 0; R < Fruits.size(); R++) {
      ++IntervalFruitCount[Fruits[R]];
      if (IntervalFruitCount.size() <= 2) {
        Max = std::max(Max, R - L + 1);
      } else {
        while (IntervalFruitCount.size() > 2) {
          if (--IntervalFruitCount[Fruits[L]] == 0) {
            IntervalFruitCount.erase(Fruits[L]);
          }
          ++L;
        }
      }
    }
    return Max;
  }
};
