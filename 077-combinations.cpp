#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> combine(int N, int K) {
    K_ = K;
    N_ = N;
    std::vector<int> Combination;
    backtrack_(Combination, 1);
    return Result_;
  }

private:
  std::vector<std::vector<int>> Result_;
  int K_;
  int N_;

  void backtrack_(std::vector<int> &Combination, int Idx) {
    if (Combination.size() == K_) {
      Result_.push_back(Combination);
      return;
    }

    if (Idx > N_) {
      return;
    }

    Combination.push_back(Idx);
    backtrack_(Combination, Idx + 1);
    Combination.pop_back(); // Restore state.

    backtrack_(Combination, Idx + 1);
  }
};
