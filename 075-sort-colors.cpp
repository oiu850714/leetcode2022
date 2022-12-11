#include "headers.hpp"

class Solution {
public:
  void sortColors(std::vector<int> &Nums) {
    int RedEnd = 0;
    for (int i = 0; i < Nums.size(); i++) {
      if (Nums[i] == 0) {
        std::swap(Nums[i], Nums[RedEnd++]);
      }
    }
    int WhiteEnd = RedEnd;
    for (int i = RedEnd; i < Nums.size(); i++) {
      if (Nums[i] == 1) {
        std::swap(Nums[i], Nums[WhiteEnd++]);
      }
    }
    // Then all elements starting from WhiteEnd are all blue.
  }
};
