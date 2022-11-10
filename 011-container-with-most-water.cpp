#include "headers.hpp"

// The hard part is the proof of correctness.
// Refer to:
// https://leetcode.com/problems/container-with-most-water/discuss/6099/yet-another-way-to-see-what-happens-in-the-on-algorithm

class Solution {
public:
  int maxArea(std::vector<int> &Height) {
    int Left = 0, Right = Height.size() - 1;
    int Max = 0;
    while (Left < Right) {
      if (Height[Left] < Height[Right]) {
        Max = std::max(Max, Height[Left] * (Right - Left));
        Left++;
      } else {
        Max = std::max(Max, Height[Right] * (Right - Left));
        Right--;
      }
    }
    return Max;
  }
};