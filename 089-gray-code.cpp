#include "headers.hpp"

class Solution {
public:
  std::vector<int> grayCode(int NumBits) {
    std::vector<int> Result{0};
    for (int i = 0; i < NumBits; i++) {
      auto ReversedResult = getReversed_(Result);
      for (int j = 0; j < ReversedResult.size(); j++) {
        ReversedResult[j] |= 1 << i;
      }
      Result.reserve(Result.size() * 2);
      Result.insert(Result.end(), ReversedResult.begin(), ReversedResult.end());
    }
    return Result;
  }

private:
  std::vector<int> getReversed_(std::vector<int> Result) {
    std::reverse(Result.begin(), Result.end());
    return Result;
  }
};
