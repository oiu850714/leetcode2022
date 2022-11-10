#include "headers.hpp"

class Solution {
public:
  int maxLength(std::vector<std::string> &Arr) {
    std::vector<std::string> ArrWithoutDup;
    for (auto const &Str : Arr) {
      // The test cases have string with duplicate characters.
      if (!hasDupChar(Str)) {
        ArrWithoutDup.push_back(Str);
      }
    }
    Arr = std::move(ArrWithoutDup);
    Arr_ = &Arr;
    std::vector<int> CharCount(26);
    backtrack_(CharCount, 0);
    return MaxLength_;
  }

private:
  int MaxLength_ = 0;
  std::vector<std::string> *Arr_;

  void backtrack_(std::vector<int> &CharCount, int WordIdx) {
    if (WordIdx == Arr_->size()) {
      auto Length = std::accumulate(CharCount.begin(), CharCount.end(), 0);
      MaxLength_ = std::max(MaxLength_, Length);
      return;
    }

    if (!hasDuplicate(CharCount, WordIdx)) {
      updateCharCount(CharCount, WordIdx);
      backtrack_(CharCount, WordIdx + 1);
      restoreCharCount(CharCount, WordIdx);
    }
    backtrack_(CharCount, WordIdx + 1);
  }

  bool hasDuplicate(const std::vector<int> &CharCount, int WordIdx) {
    for (auto Char : (*Arr_)[WordIdx]) {
      if (CharCount[Char - 'a']) {
        return true;
      }
    }
    return false;
  }

  bool hasDupChar(const std::string &S) {
    int WC[26] = {0};
    for (auto C : S) {
      if (WC[C - 'a']) {
        return true;
      }
      WC[C - 'a']++;
    }
    return false;
  }

  void updateCharCount(std::vector<int> &CharCount, int WordIdx) {
    for (auto Char : (*Arr_)[WordIdx]) {
      CharCount[Char - 'a']++;
    }
  }

  void restoreCharCount(std::vector<int> &CharCount, int WordIdx) {
    for (auto Char : (*Arr_)[WordIdx]) {
      CharCount[Char - 'a']--;
    }
  }
};
