#include "headers.hpp"

class Solution {
public:
  int trap(const std::vector<int> &Height) {
    int Ret = 0;
    auto LeftHighestForEachPoint = leftHighestElevationOfEach_(Height),
         RightHighestForEachPoint = rightHighestElevationOfEach_(Height);
    for (int i = 0; i < Height.size(); i++) {
      // The water that can be collected at index i is determined by the min of
      // its left highest elevation and right highest elevation.
      auto WaterHeight =
          std::min(LeftHighestForEachPoint[i], RightHighestForEachPoint[i]) -
          Height[i];
      if (WaterHeight > 0) {
        Ret += WaterHeight;
      }
    }
    return Ret;
  }

private:
  std::vector<int> leftHighestElevationOfEach_(const std::vector<int> &Height) {
    int CurrLeftMax = 0;
    std::vector<int> Ret(Height.size());

    // The leftmost, by definition, has no elevation at its left.
    // So we start at second position.
    for (int i = 1; i < Height.size(); i++) {
      CurrLeftMax = std::max(CurrLeftMax, Height[i - 1]);
      Ret[i] = CurrLeftMax;
    }
    return Ret;
  }
  std::vector<int>
  rightHighestElevationOfEach_(const std::vector<int> &Height) {
    int CurrRightMax = 0;
    std::vector<int> Ret(Height.size());

    // The rightmost, by definition, has no elevation at its right.
    // So we start at second to the last position.
    for (int i = Height.size() - 2; i >= 0; i--) {
      CurrRightMax = std::max(CurrRightMax, Height[i + 1]);
      Ret[i] = CurrRightMax;
    }
    return Ret;
  }
};
