#include "headers.hpp"

class Solution {
public:
  // Similar to 435.
  int findMinArrowShots(std::vector<std::vector<int>> &Points) {
    // Sort by END POINT.
    std::sort(Points.begin(), Points.end(),
              [](const auto &P1, const auto &P2) { return P1[1] < P2[1]; });
    int MaxNonOverlap = 1;
    int SelectedPointWithLatestEnd = 0;
    for (int i = 1; i < Points.size(); i++) {
      // Note that the condition is slightly different from 435.
      if (Points[i][0] <= Points[SelectedPointWithLatestEnd][1]) {
        continue;
      }
      MaxNonOverlap++;
      SelectedPointWithLatestEnd = i;
    }

    return MaxNonOverlap;
  }
};
