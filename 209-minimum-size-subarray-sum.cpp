#include "headers.hpp"

class Solution {
public:
  // This is in fact very similar to 076.
  int minSubArrayLen(int Target, std::vector<int> &Nums) {
    int Max = std::numeric_limits<int>::max();
    int Sum = 0;
    // Interval is [L, R], i.e. closed interval.
    for (int L = 0, R = 0; R < Nums.size(); R++) {
      Sum += Nums[R];
      if (Sum < Target) {
        continue;
      }
      while (Sum >= Target) {
        Max = std::min(Max, R - L + 1);
        Sum -= Nums[L++];
      }
    }
    return Max == std::numeric_limits<int>::max() ? 0 : Max;
  }
};
