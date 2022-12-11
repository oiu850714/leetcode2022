#include "headers.hpp"

class Solution {
public:
  // A more cleaner one-pass solution.
  // It treats Blue differently.
  void sortColors(std::vector<int> &Nums) {
    constexpr auto Red = 0, White = 1, Blue = 2;
    int RedEnd = 0, BlueHead = Nums.size();
    for (int WhiteEnd = 0; WhiteEnd < BlueHead;) {
      if (Nums[WhiteEnd] == Blue) {
        std::swap(Nums[WhiteEnd], Nums[--BlueHead]);
      } else if (Nums[WhiteEnd] == Red) {
        std::swap(Nums[RedEnd++], Nums[WhiteEnd++]);
      } else {
        WhiteEnd++;
      }
    }
  }
};
