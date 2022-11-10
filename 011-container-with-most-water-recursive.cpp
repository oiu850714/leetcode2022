#include "headers.hpp"

// Recursive version, which is structurally more easy to prove using induction.
// P(n): The algorithm can compute the maximum containing water for n endpoints.
// Base case: P(2), trivial.
// Refer to:
// https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm

class Solution {
public:
  int maxArea(std::vector<int> &Height) {
    return maxAreaRecursive(Height, 0, Height.size());
  }

private:
  int maxAreaRecursive(const std::vector<int> &Height, int Start, int End) {
    if (End - Start == 2) {
      return std::min(Height[Start], Height[Start + 1]);
    }

    if (Height[Start] < Height[End - 1]) {
      auto Max = Height[Start] * (End - 1 - Start);
      return std::max(Max, maxAreaRecursive(Height, Start + 1, End));
    } else {
      auto Max = Height[End - 1] * (End - 1 - Start);
      return std::max(Max, maxAreaRecursive(Height, Start, End - 1));
    }
  }
};