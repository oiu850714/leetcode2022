#include "headers.hpp"

using Intervals = std::vector<std::vector<int>>;
using Interval = std::vector<int>;

class Solution {
public:
  Intervals insert(Intervals &SortedIntervals, Interval &NewInterval) {
    Intervals Ret;
    for (int i = 0; i < SortedIntervals.size(); i++) {
      if (NewInterval[1] < SortedIntervals[i][0]) {
        // All remaining intervals are nonoverlapping with and on the right of
        // NewInterval.
        Ret.push_back(NewInterval);
        while (i < SortedIntervals.size()) {
          Ret.push_back(SortedIntervals[i++]);
        }
        return Ret;
      } else if (NewInterval[0] > SortedIntervals[i][1]) {
        // Else if the current interval is nonoverlapping and on the left of
        // NewInterval.
        Ret.push_back(SortedIntervals[i]);
      } else {
        // Else, the current interval "is" overlapping with NewInterval.
        // So we merge them together and "expand" NewInterval.
        NewInterval = {std::min(NewInterval[0], SortedIntervals[i][0]),
                       std::max(NewInterval[1], SortedIntervals[i][1])};
      }
    }
    // If the loop exits, then the first if branch in the loop is never
    // executed, which implies we have not add the (merged) NewInterval to the
    // Ret yet.
    Ret.push_back(NewInterval);
    return Ret;
  }

private:
  bool canMerge_(const Interval &First, const Interval &Second) {
    return First[1] >= Second[0] && First[0] <= Second[1];
  }
};