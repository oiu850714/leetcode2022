#include "headers.hpp"

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &Nums, int Target) {
    // By assumption, Nums.size() >= 2.
    for (int firstIdx = 0, secondIdx = Nums.size() - 1; firstIdx < secondIdx;) {
      if (Nums[firstIdx] + Nums[secondIdx] == Target) {
        return {firstIdx + 1, secondIdx + 1};
      } else if (Nums[firstIdx] + Nums[secondIdx] > Target) {
        secondIdx--;
      } else {
        firstIdx++;
      }
    }
    throw; // By assumption, this is impossible.
  }
};