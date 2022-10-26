#include "headers.hpp"

using Intervals = std::vector<std::vector<int>>;
using Interval = std::vector<int>;

class Solution {
public:
  Intervals merge(Intervals &OldIntervals) {
    if (OldIntervals.empty()) {
      return {};
    }

    // C++20 removed operaotr<() for std::vector.
    // Sort the interval first by left bound and second by right bound.
    // Assume the interval always has two elements.
    std::sort(OldIntervals.begin(), OldIntervals.end(),
              [](const Interval &I1, const Interval &I2) {
                return I1[0] < I2[0] || (I1[0] == I2[0] && I1[1] < I2[1]);
              });

    Intervals MergedIntervals;
    for (auto &OldInterval : OldIntervals) {
      if (MergedIntervals.empty()) {
        MergedIntervals.push_back(OldInterval);
        continue;
      }

      auto &Back = MergedIntervals.back();
      if (canMerge_(Back, OldInterval)) {
        // The invariant is that, after merging, MergedIntervals is still
        // sorted; that is, the new merged interval of back() and OldInterval is
        // still the "largest" interval in MergedIntervals.
        Back[1] = std::max(Back[1], OldInterval[1]);
      } else {
        MergedIntervals.push_back(OldInterval);
      }
    }
    return MergedIntervals;
  }

private:
  // Assume the left bound of I1 is less than or equal to I2.
  bool canMerge_(const Interval &I1, const Interval &I2) {
    return I1[1] >= I2[0];
  }
};