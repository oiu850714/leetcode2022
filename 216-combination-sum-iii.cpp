#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> combinationSum3(int K, int N) {
    K_ = K;
    N_ = N;
    std::vector<int> Subset;
    backtrack_(Subset, 0, 1);
    return std::move(Result_);
  }

private:
  std::vector<std::vector<int>> Result_;
  void backtrack_(std::vector<int> &Subset, int Sum, int CurrNum) {
    if (Subset.size() == K_) {
      // We have select K numbers.
      // In all cases, where sum of the numbers >, ==, < N, we must return.
      if (Sum == N_) {
        Result_.push_back(Subset);
        return;
      } else {
        return;
      }
    }

    // Now Subset have less than K numbers.
    if (Sum == N_) {
      // Subset sums to N, but have less than K numbers.
      return;
    }

    // We have considered all numbers but the sum is still less than N.
    if (CurrNum > 9) {
      return;
    }

    // Include CurrNum.
    Subset.push_back(CurrNum);
    backtrack_(Subset, Sum + CurrNum, CurrNum + 1);
    Subset.pop_back();

    // Exclude CurrNum.
    backtrack_(Subset, Sum, CurrNum + 1);
  }
  int K_;
  int N_;
};