#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &Nums) {
    std::vector<int> PermuPrefix;
    backtrack_(Nums, PermuPrefix);
    return std::move(Permutations_);
  }

private:
  void backtrack_(std::vector<int> &Nums, std::vector<int> &PermuPrefix) {
    if (PermuPrefix.size() == Nums.size()) {
      Permutations_.push_back(PermuPrefix);
      return;
    }

    for (auto Num : Nums) {
      if (std::find(PermuPrefix.begin(), PermuPrefix.end(), Num) ==
          PermuPrefix.end()) {
        PermuPrefix.push_back(Num);
        backtrack_(Nums, PermuPrefix);
        PermuPrefix.pop_back();
      }
    }
  }
  std::vector<std::vector<int>> Permutations_;
};