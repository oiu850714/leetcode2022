#include "headers.hpp"

class Solution {
public:
  std::vector<std::string> restoreIpAddresses(std::string S) {
    if (S.size() < 4 || S.size() > 12) {
      // S is too long or too short to become valid.
      return {};
    }
    // Mark the end of each part of IP.
    std::vector<int> PointsIdx{};
    S_ = &S;
    backtrack_(PointsIdx);
    return std::move(Result_);
  }

private:
  std::vector<std::string> Result_;
  std::string const *S_;

  void backtrack_(std::vector<int> &PointsIdx) {
    // Get 4 valid parts,
    if (PointsIdx.size() == 4) {
      // and have used all digits.
      if (PointsIdx.back() == S_->size()) {
        Result_.push_back(toIP_(PointsIdx));
      }
      return;
    }

    int Beg = !PointsIdx.empty() ? PointsIdx.back() : 0;
    // End marks the end of new part, so it can be S_->size().
    for (int End = Beg + 1; End <= S_->size() && isValidInterval_(Beg, End);
         End++) {
      PointsIdx.push_back(End);
      backtrack_(PointsIdx);
      PointsIdx.pop_back();
    }
  }

  // Assume End - Beg >= 1.
  bool isValidInterval_(int Beg, int End) {
    std::string Part(S_->begin() + Beg, S_->begin() + End);
    if (Part.size() == 1) {
      // A single digit.
      return true;
    } else if (Part.size() > 1 && Part[0] == '0') {
      // Two digits: cannot start with zero.
      return false;
    } else if (Part.size() == 2) {
      return true;
    } else if (Part.size() == 3) {
      // Three digits: Can only have 1XX, 2XX.
      if (Part[0] == '1') {
        return true;
      } else if (Part[0] == '2') {
        // In particular, for 2XX, can only be 20X, 21X, 22X, 23X, 24X, 250 ~
        // 255.
        return Part[1] == '0' || Part[1] == '1' || Part[1] == '2' ||
               Part[1] == '3' || Part[1] == '4' ||
               (Part[1] == '5' && Part[2] <= '5');
      } else {
        // 3XX to 9XX is invalid.
        return false;
      }
    } else {
      return false;
    }
  }

  std::string toIP_(std::vector<int> &PointsIdx) {
    // Note that substr API is substr(startPos, Len).
    return S_->substr(0, PointsIdx[0]) + '.' +
           S_->substr(PointsIdx[0], PointsIdx[1] - PointsIdx[0]) + '.' +
           S_->substr(PointsIdx[1], PointsIdx[2] - PointsIdx[1]) + '.' +
           S_->substr(PointsIdx[2], PointsIdx[3] - PointsIdx[2]);
  }
};