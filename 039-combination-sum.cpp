#include "headers.hpp"

class Solution {
public:
  // Note that, by assumption, all numbers in Candidates and Target are
  // positive.
  std::vector<std::vector<int>> combinationSum(std::vector<int> &Candidates,
                                               int Target) {
    // Make duplicates adjacent to each other.
    std::sort(Candidates.begin(), Candidates.end());

    Target_ = Target;
    Candidates_ = &Candidates;

    std::vector<int> Combination;
    backtrack_(0, Combination, 0);

    return std::move(Result_);
  }

private:
  std::vector<std::vector<int>> Result_;
  std::vector<int> const *Candidates_;
  int Target_;

  void backtrack_(int Curr, std::vector<int> &Combination,
                  int SelectionStartIdx) {
    if (Curr > Target_) {
      return;
    }
    if (Curr == Target_) {
      Result_.push_back(Combination);
      return;
    }

    // To prevent duplication, we choose candidate number with index GREATER
    // THAN SelectionStartIdx.
    for (int i = SelectionStartIdx; i < Candidates_->size(); i++) {
      auto Candidate = (*Candidates_)[i];
      Combination.push_back(Candidate);
      backtrack_(Curr + Candidate, Combination, i);
      Combination.pop_back();
    }
  }
};