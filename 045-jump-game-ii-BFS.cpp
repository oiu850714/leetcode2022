#include "headers.hpp"

class Solution {
public:
  int jump(std::vector<int> &Steps) {
    int SameLevelPosStart = 0, SameLevelPosEnd = 0; // "INCLUSIVE" BOUND.
    int MinStep = 0;
    while (SameLevelPosEnd < Steps.size() - 1) {
      int NextLevelEnd = SameLevelPosStart;
      for (int Pos = SameLevelPosStart; Pos <= SameLevelPosEnd; Pos++) {
        NextLevelEnd = std::max(NextLevelEnd, Pos + Steps[Pos]);
      }
      MinStep++;
      // Update the bounds for the (continuous) positions in the next level.
      SameLevelPosStart = SameLevelPosEnd + 1;
      SameLevelPosEnd = NextLevelEnd;
    }

    return MinStep;
  }
};
