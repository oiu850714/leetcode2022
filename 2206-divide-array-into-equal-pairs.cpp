#include "headers.hpp"

class Solution {
public:
  bool divideArray(std::vector<int> &Nums) {
    // Input size is small, so use sort + count.
    std::sort(Nums.begin(), Nums.end());
    for (int i = 0; i < Nums.size();) {
      int Num = Nums[i];
      int Count = 1;
      while (++i < Nums.size() && Nums[i] == Num) {
        Count++;
      }
      if (Count & 1) {
        return false;
      }
    }
    return true;
  }
};
