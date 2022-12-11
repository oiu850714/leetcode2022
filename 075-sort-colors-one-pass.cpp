#include "headers.hpp"

class Solution {
public:
  // Just my theoretically linear + one-pass sol, but MESSY.
  void sortColors(std::vector<int> &Nums) {
    constexpr auto Red = 0, White = 1, Blue = 2;
    int RedEnd = 0, WhiteEnd = 0, BlueEnd = 0;
    for (int BlueEnd = 0; BlueEnd < Nums.size();) {
      if (Nums[BlueEnd] == Red) {
        Nums[RedEnd] = Red;
        if (RedEnd != WhiteEnd) {
          // White is non empty, and we have overwrite one White element with
          // Red.
          Nums[WhiteEnd] = White;
        }
        if (WhiteEnd != BlueEnd) {
          // Blue is non empty, and we have overwrite one Blue element with
          // White, or with Red when White is empty.
          Nums[BlueEnd] = Blue;
        }
        RedEnd++;
        WhiteEnd++;
        BlueEnd++;
      } else if (Nums[BlueEnd] == White) {
        std::swap(Nums[WhiteEnd++], Nums[BlueEnd++]);
      } else {
        // Nums[BlueEnd], which is Blue, is already in the right place, just
        // need to advance BlueEnd.
        BlueEnd++;
      }
    }
  }
};
