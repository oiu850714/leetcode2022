#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &Nums) {
    std::sort(Nums.begin(), Nums.end());
    Nums_ = &Nums;
    std::vector<int> Subset;
    backtrack_(Subset, 0);
    return std::move(Result_);
  }

private:
  void backtrack_(std::vector<int> &Subset, int Idx) {
    if (Idx == Nums_->size()) {
      Result_.push_back(Subset);
      return;
    }

    // First case: All subsets that include Nums[Idx].
    Subset.push_back((*Nums_)[Idx]);
    backtrack_(Subset, Idx + 1);
    Subset.pop_back(); // Restore state.

    // Second case: All subsets that do not include Nums[Idx].
    // Note that if Nums[Idx + 1] is the same as Nums[Idx], we need to skip
    // Nums[Idx + 1], because backtrack_(Subset, Idx + 1) will find duplicates
    // already discovered in the first case.
    while (Idx + 1 < Nums_->size() && (*Nums_)[Idx] == (*Nums_)[Idx + 1]) {
      Idx++;
    }
    backtrack_(Subset, Idx + 1);
    // Since we don't change the subset, nothing to restore.
  }
  std::vector<int> const *Nums_;
  std::vector<std::vector<int>> Result_;
};