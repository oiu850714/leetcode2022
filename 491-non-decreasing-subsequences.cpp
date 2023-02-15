#include "headers.hpp"

class Solution {
  using AnsTy = std::vector<std::vector<int>>;

public:
  AnsTy findSubsequences(const std::vector<int> &Nums) {
    assert(Nums.size() <= 15);
    std::vector<int> Seq;
    backtrack_(0, Seq, Nums);
    return std::move(Ans_);
  }

private:
  AnsTy Ans_;

  void backtrack_(int CurrIdx, std::vector<int> &Seq,
                  const std::vector<int> &Nums) {
    if (Seq.size() > 1) {
      Ans_.push_back(Seq);
    }

    std::unordered_set<int> Picked;
    for (auto i = CurrIdx; i < Nums.size(); i++) {
      if (Picked.count(Nums[i])) {
        // Prevent duplication.
        continue;
      }

      if (!Seq.empty() && Seq.back() > Nums[i]) {
        // Invalid seq.
        continue;
      }
      // Pick Nums[i].
      Seq.push_back(Nums[i]);
      Picked.insert(Nums[i]);
      backtrack_(i + 1, Seq, Nums);
      Seq.pop_back(); // Restore state.
    }
  }
};
