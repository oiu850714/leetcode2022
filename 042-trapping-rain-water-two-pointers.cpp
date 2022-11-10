#include "headers.hpp"

class Solution {
public:
  int trap(const std::vector<int> &Height) {
    int Ret = 0;
    int Left = 0, Right = Height.size() - 1;
    int LeftMax = Height[0], RightMax = Height.back();
    while (Left < Right) {
      if (LeftMax < RightMax) {
        ++Left;
        auto WaterHeight = LeftMax - Height[Left];
        if (WaterHeight > 0) {
          Ret += WaterHeight;
        }
        LeftMax = std::max(LeftMax, Height[Left]);
      } else {
        --Right;
        auto WaterHeight = RightMax - Height[Right];
        if (WaterHeight > 0) {
          Ret += WaterHeight;
        }
        RightMax = std::max(RightMax, Height[Right]);
      }
    }
    return Ret;
  }
};
