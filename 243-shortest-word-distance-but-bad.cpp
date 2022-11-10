#include "headers.hpp"

class Solution {
public:
  int shortestDistance(const std::vector<std::string> &Words, std::string W1,
                       std::string W2) {
    int Ret = INT_MAX;
    auto W1Indices = getOccurredIndices_(Words, W1);
    auto W2Indices = getOccurredIndices_(Words, W2);
    for (auto W1Idx : W1Indices) {
      auto DisLastW2BeforeD1 = INT_MAX, DisFirstW2AfterW1 = INT_MAX;
      auto ClosestW2IdxAfter =
          std::lower_bound(W2Indices.begin(), W2Indices.end(), W1Idx);
      // std::upper_bound also works, since by assumption, W1 != W2, and that
      // implies W1Idx does not exist in W2Indices, hence,
      // std::lower_bound(...) == std::upper_bound(...).
      if (ClosestW2IdxAfter != W2Indices.end()) {
        DisFirstW2AfterW1 = *ClosestW2IdxAfter - W1Idx;
      }
      if (ClosestW2IdxAfter != W2Indices.begin()) {
        DisLastW2BeforeD1 = W1Idx - *(ClosestW2IdxAfter - 1);
      }
      auto ClosestW2ForThisW1 = std::min(DisLastW2BeforeD1, DisFirstW2AfterW1);
      Ret = std::min(Ret, ClosestW2ForThisW1);
    }
    return Ret;
  }

private:
  std::vector<int> getOccurredIndices_(const std::vector<std::string> &Words,
                                       const std::string &Word) {
    std::vector<int> Ret;
    for (int i = 0; i < Words.size(); i++) {
      if (Words[i] == Word) {
        Ret.push_back(i);
      }
    }
    return Ret;
  }
};
