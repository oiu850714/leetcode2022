#include "headers.hpp"

using PartitionTy = std::vector<std::string>;
using PartitionsTy = std::vector<std::vector<std::string>>;
class Solution {
public:
  PartitionsTy partition(std::string S) {
    S_ = std::move(S);
    constructTable_();
    std::vector<int> PartitionPoints{0};
    backtrack_(PartitionPoints);
    return std::move(Result_);
  }

private:
  PartitionsTy Result_;
  std::vector<std::vector<int>>
      DPTable_; // Store whether S[i, j] (closed interval) is a palindrome.
  std::string S_;

  // Assume PartitionPoints is nonempty.
  void backtrack_(std::vector<int> &PartitionPoints) {
    if (PartitionPoints.back() == S_.size()) {
      Result_.push_back(convertSToPartitions_(PartitionPoints));
      return;
    }

    // Note that the condition is <=, not <, since we need to pass the right
    // bound to the checking function.
    for (int Right = PartitionPoints.back() + 1; Right <= S_.size(); Right++) {
      if (DPTable_[PartitionPoints.back()][Right]) {
        PartitionPoints.push_back(Right);
        backtrack_(PartitionPoints);
        PartitionPoints.pop_back();
      }
    }
  }

  // Modified from 005.
  // Note that I changed the closed interval logic to half-open interval logic.
  // That is, DPTable_ stores half-open intervals.
  void constructTable_() {
    DPTable_ = std::vector<std::vector<int>>(S_.size() + 1,
                                             std::vector<int>(S_.size() + 1));
    for (int i = 0; i < S_.size(); i++) {
      // The case where the center is in a character S[i]
      for (int j = 0; i - j >= 0; j++) {
        if (S_[i - j] != S_[i + j]) {
          break;
        }
        // S[i - j, i + j + 1) is a palindrome.
        DPTable_[i - j][i + j + 1] = 1;
      }
      // The case where the center is between two characters S[i] and S[i + 1].
      for (int j = 0; i - j >= 0; j++) {
        if (S_[i - j] != S_[i + j + 1]) {
          break;
        }
        // S[i - j, i + j + 1 + 1) is a palindrome.
        DPTable_[i - j][(i + j + 1) + 1] = 1;
      }
    }
  }

  // Assume PartitionPoints.size() >= 2
  // And each point except the first one marks the END(including) of a
  // palindrome, so the beginning of each palindrome is the index + 1.
  PartitionTy convertSToPartitions_(const std::vector<int> &PartitionPoints) {
    PartitionTy Ret;
    for (int i = 0; i < PartitionPoints.size() - 1; i++) {
      auto Start = PartitionPoints[i], End = PartitionPoints[i + 1];
      Ret.push_back(S_.substr(Start, End - Start));
    }
    return Ret;
  }
};