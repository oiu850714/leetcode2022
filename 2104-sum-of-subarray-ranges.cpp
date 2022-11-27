#include "headers.hpp"

class Solution {
public:
  long long subArrayRanges(std::vector<int> &Nums) {
    auto NextGreaterOrEqual =
        nextElementWithPred_(Nums, std::greater_equal<int>());
    auto NextSmallerOrEqual =
        nextElementWithPred_(Nums, std::less_equal<int>());
    auto PrevGreater = prevElementWithPred_(Nums, std::greater<int>());
    auto PrevSmaller = prevElementWithPred_(Nums, std::less<int>());

    long long AllRangeMaxSum = 0, AllRangeMinSum = 0;
    for (int i = 0; i < Nums.size(); i++) {
      // Cast long long to prevent int overflow.
      AllRangeMaxSum += ((NextGreaterOrEqual[i] - i) * (i - PrevGreater[i])) *
                        (long long)Nums[i];
      AllRangeMinSum += ((NextSmallerOrEqual[i] - i) * (i - PrevSmaller[i])) *
                        (long long)Nums[i];
    }
    return AllRangeMaxSum - AllRangeMinSum;
  }

private:
  // Modified from 496.
  template <typename Pred>
  std::vector<int> nextElementWithPred_(const std::vector<int> &Nums,
                                        Pred &&P) {
    // Notice the initial value is set to the "rightmost" index.
    std::vector<int> Ret(Nums.size(), Nums.size());

    std::stack<int> MonoStack;
    for (int i = 0; i < Nums.size(); i++) {
      while (!MonoStack.empty() && P(Nums[i], Nums[MonoStack.top()])) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }

  template <typename Pred>
  std::vector<int> prevElementWithPred_(const std::vector<int> &Nums,
                                        Pred &&P) {
    // Notice the initial value is set to the "leftmost" index.
    std::vector<int> Ret(Nums.size(), -1);

    std::stack<int> MonoStack;
    for (int i = Nums.size() - 1; i >= 0; i--) {
      while (!MonoStack.empty() && P(Nums[i], Nums[MonoStack.top()])) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }
};
