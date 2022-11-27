#include "headers.hpp"

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &Temperatures) {
    std::stack<int> MonoIdxStack;
    std::vector<int> DaysAfterToFindWarmer(Temperatures.size());
    for (int CurrDay = 0; CurrDay < Temperatures.size(); CurrDay++) {
      while (!MonoIdxStack.empty() &&
             Temperatures[MonoIdxStack.top()] < Temperatures[CurrDay]) {
        DaysAfterToFindWarmer[MonoIdxStack.top()] =
            CurrDay - MonoIdxStack.top();
        MonoIdxStack.pop();
      }
      MonoIdxStack.push(CurrDay);
    }
    return DaysAfterToFindWarmer;
  }
};
