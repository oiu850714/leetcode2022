#include "headers.hpp"

class Solution {
public:
  std::vector<std::string> generateParenthesis(int N) {
    N_ = N;
    std::string Curr;
    Curr.reserve(2 * N);
    backtrack_(Curr, 0, 0);
    return Result_;
  }

private:
  int N_;
  std::vector<std::string> Result_;

  void backtrack_(std::string &Curr, int UsedOpen, int UsedClose) {
    if (Curr.size() == 2 * N_) {
      // There are two questions we may have:
      // 1. Why Curr must be valid?
      // 2. Why Curr won't duplicate with existing strings in Result_?
      Result_.push_back(Curr);
      return;
    }

    if (UsedOpen < N_) {
      Curr.push_back('(');
      backtrack_(Curr, UsedOpen + 1, UsedClose);
      Curr.pop_back();
    }

    if (UsedClose < UsedOpen) {
      Curr.push_back(')');
      backtrack_(Curr, UsedOpen, UsedClose + 1);
      Curr.pop_back();
    }
  }
};
