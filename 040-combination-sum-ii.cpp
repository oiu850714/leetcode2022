#include "headers.hpp"

class Solution {
public:
  // Note that, like 039. and by assumption, all numbers in Candidates and
  // Target are positive.
  // By the way, this problem is actually more similar to 090.
  // That is, we need to enumerate all subsets(remove duplicates) and check the
  // sum of each subset is equal to target.
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &Candidates,
                                                int Target) {
    std::sort(Candidates.begin(), Candidates.end());
    Candidates_ = &Candidates;
    Target_ = Target;
    std::vector<int> Subset;
    backtrack_(Subset, 0, 0);
    return std::move(Result_);
  }

private:
  void backtrack_(std::vector<int> &Subset, int Idx, int Sum) {
    if (Sum == Target_) {
      Result_.push_back(Subset);
      return;
    } else if (Sum > Target_) {
      // The sum of current Sub is too big.
      // Any set found by further backtrack_ will also include this subset
      // hence be too big.
      return;
    } else if (Sum < Target_ && Idx == Candidates_->size()) {
      // The sum is too small, but we have considered all numbers in the
      // Candidates.
      return;
    }

    // First case: All subsets that include Candidates[Idx].
    Subset.push_back((*Candidates_)[Idx]);
    backtrack_(Subset, Idx + 1, Sum + (*Candidates_)[Idx]);
    Subset.pop_back(); // Restore state.

    // Second case: All subsets that do not include Candidates[Idx].
    // Note that if Candidates[Idx + 1] is the same as Candidates[Idx], we need
    // to skip Candidates[Idx + 1], because backtrack_(Subset, Idx + 1) will
    // find duplicates already discovered in the first case.
    while (Idx + 1 < Candidates_->size() &&
           (*Candidates_)[Idx] == (*Candidates_)[Idx + 1]) {
      Idx++;
    }
    backtrack_(Subset, Idx + 1, Sum);
    // Since we don't change the subset, nothing to restore.
  }
  std::vector<int> const *Candidates_;
  std::vector<std::vector<int>> Result_;
  int Target_;
};