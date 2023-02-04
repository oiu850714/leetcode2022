#include "headers.hpp"

class Solution {
public:
  int findRadius(std::vector<int> &Houses, std::vector<int> &Heaters) {
    // Input is not sorted.
    std::sort(Houses.begin(), Houses.end());
    std::sort(Heaters.begin(), Heaters.end());

    int Ret = 0;
    for (auto HousePos : Houses) {
      auto R =
          std::numeric_limits<int>::max(); // Store the distance from the
                                           // HousePos to the nearest Heater.
      auto NearestRightHeater =
          std::lower_bound(Heaters.begin(), Heaters.end(), HousePos);
      if (NearestRightHeater == Heaters.end()) {
        // There is no heater after HousePos.
        R = HousePos - Heaters.back();
      } else if (NearestRightHeater == Heaters.begin()) {
        // There is no heater before HousePos.
        R = Heaters.front() - HousePos;
      } else {
        // Else
        R = std::min(*NearestRightHeater - HousePos,
                     HousePos - *(NearestRightHeater - 1));
      }
      Ret = std::max(Ret, R);
    }
    return Ret;
  }
};
