#include "headers.hpp"

class Solution {
  // Modified and simplified from 2104.
public:
  int sumSubarrayMins(std::vector<int> &Nums) {
    auto NextSmallerOrEqual =
        nextElementWithPred_(Nums, std::less_equal<int>());
    auto PrevSmaller = prevElementWithPred_(Nums, std::less<int>());

    long long Ret = 0;
    for (int i = 0; i < Nums.size(); i++) {
      Ret += (i - PrevSmaller[i]) * (NextSmallerOrEqual[i] - i) *
             (long long)Nums[i];
    }
    return Ret % 1000000007;
  }

private:
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
