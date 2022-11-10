#include "headers.hpp"

class Solution {
public:
  bool canAttendMeetings(std::vector<std::vector<int>> &Intervals) {
    if (Intervals.size() <= 1) {
      return true;
    }

    std::sort(Intervals.begin(), Intervals.end());
    for (int i = 0; i < Intervals.size() - 1; i++) {
      if (Intervals[i][1] > Intervals[i + 1][0]) {
        return false;
      }
    }
    return true;
  }
};
