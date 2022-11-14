#include "headers.hpp"

class Solution {
public:
  int jump(std::vector<int> &Steps) {
    std::vector<int> MinStepsToReachEnd(Steps.size(), Steps.size());
    MinStepsToReachEnd.back() = 1;

    for (int CurrPos = Steps.size() - 2; CurrPos >= 0; CurrPos--) {
      if (CurrPos + Steps[CurrPos] >= Steps.size() - 1) {
        MinStepsToReachEnd[CurrPos] = 1;
        continue;
      }

      int MaxReachablePos =
          std::min<int>(CurrPos + Steps[CurrPos], Steps.size() - 1);
      MinStepsToReachEnd[CurrPos] =
          1 +
          *std::min_element(MinStepsToReachEnd.begin() + CurrPos,
                            MinStepsToReachEnd.begin() + MaxReachablePos + 1);
    }
    return MinStepsToReachEnd[0];
  }
};
