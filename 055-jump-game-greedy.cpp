#include "headers.hpp"

class Solution {
public:
  bool canJump(std::vector<int> &Steps) {
    int LeftMostReachablePos = Steps.size() - 1;

    for (int CurrPos = Steps.size() - 2; CurrPos >= 0; CurrPos--) {
      // If we can take a step from CurrPos reach to the current-seen leftmost
      // reachable position:
      if (CurrPos + Steps[CurrPos] >= LeftMostReachablePos) {
        LeftMostReachablePos = CurrPos;
      }
    }
    return LeftMostReachablePos == 0;
  }
};
