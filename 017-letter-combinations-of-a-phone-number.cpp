#include "headers.hpp"

static std::unordered_map<char, std::vector<char>> Map{
    {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}},
};
class Solution {
public:
  std::vector<std::string> letterCombinations(std::string Digits) {
    Digits_ = std::move(Digits);
    std::string Combination;
    backtrack_(Combination, 0);
    return std::move(Result_);
  }

private:
  std::vector<std::string> Result_;
  std::string Digits_;

  void backtrack_(std::string &Combination, size_t Idx) {
    if (Idx != 0 && // != 0 for the case of empty Digits_.
        Idx == Digits_.size()) {
      Result_.push_back(Combination);
      return;
    }

    for (auto Digit : Map[Digits_[Idx]]) {
      Combination.push_back(Digit);
      backtrack_(Combination, Idx + 1);
      Combination.pop_back(); // Restore state.
    }
  }
};
