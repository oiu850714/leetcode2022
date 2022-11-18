#include "headers.hpp"

class Solution {
public:
  int canCompleteCircuit(std::vector<int> &Gas, std::vector<int> &Cost) {
    // First, the solution exists IF AND ONLY IF sum(Gas) >= sum(Cost).
    // =>: This direction is intuitive.
    // <=: See
    //     https://leetcode.com/problems/gas-station/discuss/42572/Proof-of-%22if-total-gas-is-greater-than-total-cost-there-is-a-solution%22.-C%2B%2B
    if (std::accumulate(Gas.begin(), Gas.end(), 0) <
        std::accumulate(Cost.begin(), Cost.end(), 0)) {
      return -1;
    }

    // Now we are guaranteed that the solution exists.
    // The leetcode link above also derives how to find the solution.
    int CurrTank = 0;
    int MinTank = 0;
    int MinTankPos = 0;
    for (int i = 0; i < Gas.size(); i++) {
      CurrTank += Gas[i] - Cost[i];
      if (CurrTank < MinTank) {
        MinTankPos = i + 1;
        MinTank = CurrTank;
      }
    }
    return MinTankPos;
  }
};
