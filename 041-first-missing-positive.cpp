#include "headers.hpp"

class Solution {
public:
  int firstMissingPositive(std::vector<int> &Nums) {
    // Refer to awesome discussion:
    // https://leetcode.com/problems/first-missing-positive/discussion/comments/1564577
    int N = Nums.size();
    for (auto &Num : Nums) {
      if (Num > N || Num < 1) {
        Num = N + 1;
      }
    }
    for (auto Num : Nums) {
      auto NumAbs = std::abs(Num), Idx = NumAbs - 1;
      if (1 <= NumAbs && NumAbs <= N) {
        Nums[Idx] = -std::abs(Nums[Idx]);
      }
    }
    for (int i = 0; i < Nums.size(); i++) {
      if (Nums[i] > 0) {
        return i + 1;
      }
    }
    return N + 1;
  }
};
