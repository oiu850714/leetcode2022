#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> subsets(const std::vector<int> &Nums) {
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
    backtrack_(Subset, Idx + 1);
    // Since we don't change the subset, nothing to restore.
  }
  std::vector<int> const *Nums_;
  std::vector<std::vector<int>> Result_;
};