#include "headers.hpp"

class Solution {
public:
  // It's a variation of problem 084., 907., and so on.
  int validSubarraySize(std::vector<int> &Nums, int Threshold) {
    auto [PrevSmaller, NextSmaller] = prevAndNextSmaller_(Nums);
    for (int i = 0; i < Nums.size(); i++) {
      auto RangeWidth = (i - PrevSmaller[i]) + (NextSmaller[i] - i) - 1;
      if ((double)Nums[i] > (double)Threshold / RangeWidth) {
        return RangeWidth;
      }
    }
    return -1;
  }

private:
  std::pair<std::vector<int>, std::vector<int>>
  prevAndNextSmaller_(const std::vector<int> &Nums) {
    std::vector<int> PrevSmaller(Nums.size(), -1);
    std::vector<int> NextSmaller(Nums.size(), Nums.size());
    std::stack<int> MonoStack;
    for (int i = 0; i < Nums.size(); i++) {
      while (!MonoStack.empty() && Nums[MonoStack.top()] > Nums[i]) {
        NextSmaller[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    MonoStack = std::stack<int>{};
    for (int i = Nums.size() - 1; i >= 0; i--) {
      while (!MonoStack.empty() && Nums[MonoStack.top()] > Nums[i]) {
        PrevSmaller[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return {PrevSmaller, NextSmaller};
  }
};
