#include "headers.hpp"

class Solution {
public:
  bool canPlaceFlowers(const std::vector<int> &Bed, int N) {
    int AvailSlots = 0;
    auto B = std::find(Bed.begin(), Bed.end(), 1);
    if (B == Bed.end()) {
      // edge case: the bed is totally empty.
      return (Bed.size() + 1) / 2 >= N;
    }

    // There are 3 cases for which we calculate the available slots.
    // case 1: the available slots BEFORE the first plant.
    // B - Bed.begin() is the number of empty slots before the first plant.
    AvailSlots += (B - Bed.begin()) / 2;
    for (auto NextOne = std::find(B + 1, Bed.end(), 1);
         B != Bed.end();) {
      // NextOne - B - 1 is the number of empty slots for each interval.
      const auto EmptySlots = NextOne - B - 1;
      if (NextOne == Bed.end()) {
        // case 2: the available slots AFTER the last plant.
        AvailSlots += std::max<int>(EmptySlots / 2, 0);
      } else {
        // case 3: the available slots between each pair of plants.
        AvailSlots += std::max<int>((EmptySlots - 1 ) / 2, 0);
      }
      B = NextOne;
      NextOne = std::find(B + 1, Bed.end(), 1);
    }
    return AvailSlots >= N;
  }
};
