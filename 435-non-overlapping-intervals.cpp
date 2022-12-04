#include "headers.hpp"

class Solution {
public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &Intervals) {
    // Sort by END TIME.
    std::sort(Intervals.begin(), Intervals.end(),
              [](const auto &I1, const auto &I2) { return I1[1] < I2[1]; });
    // This "greedy" algo is essentially "DP + the assumption of sorted (by end
    // time) input". And the proof heavily uses the DP concept.
    int MaxNonOverlap = 1;
    int SelectedIntervalWithLatestEnd = 0;
    for (int i = 1; i < Intervals.size(); i++) {
      if (Intervals[i][0] < Intervals[SelectedIntervalWithLatestEnd][1]) {
        continue;
      }
      MaxNonOverlap++;
      SelectedIntervalWithLatestEnd = i;
    }

    return Intervals.size() - MaxNonOverlap;
  }
};
