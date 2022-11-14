#include "headers.hpp"

class Solution {
public:
  bool canJump(std::vector<int> &Steps) {
    // DPTable[CurrPos] stores whether we can reach the last position if we
    // start at CurrPos.
    std::vector<bool> DPTable(Steps.size());
    DPTable.back() = true;

    for (int CurrPos = Steps.size() - 2; CurrPos >= 0; CurrPos--) {
      const int NextPos = CurrPos + 1;
      if ( // If we cannot rach the last position when we start from next pos,
           // that means DPTable[NextPos + 1],
           //       DPTable[NextPos + 1 + 2],
           //       DPTable[NextPos + 1 + 3],
           //       ...
           //       DPTable[NextPos + 1 + Steps[NextPos + 1]] are ALSO ALL
           //       FALSE.
           // Because if any of them is true, that is, if we can reach the end
           // when starting for NextPos + k for some k < Steps[NextPos], then we
           // can reach the end from NextPos by taking k steps to reach NextPos
           // + k, and reach the end from that position.
          DPTable[NextPos] == false &&

          // So if the rightmost position we can reach by taking steps in
          // CurrPos is still less than NextPos + Steps[NextPos], then that
          // implies all positions we can go from CurrPos cannot reach the end,
          // hence we cannot reach the end from CurrPos.
          (CurrPos + Steps[CurrPos] < NextPos + Steps[NextPos])) {

        continue;
      }
      int RightmostAttemptPos =
          std::min<int>((Steps.size() - 1), (CurrPos + Steps[CurrPos]));
      for (int AttemptStep = NextPos; AttemptStep <= RightmostAttemptPos;
           AttemptStep++) {
        if (DPTable[AttemptStep] == true) {
          DPTable[CurrPos] = true;
          break;
        }
      }
    }
    return DPTable.front();
  }
};
