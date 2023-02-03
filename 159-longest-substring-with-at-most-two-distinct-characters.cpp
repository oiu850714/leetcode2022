#include "headers.hpp"

class Solution {
public:
  int lengthOfLongestSubstringTwoDistinct(const std::string &S) {
    std::unordered_map<char, int> IntervalCharCount;
    int Max = 0;
    for (int L = 0, R = 0; R < S.size(); R++) {
      ++IntervalCharCount[S[R]];
      if (IntervalCharCount.size() <= 2) {
        Max = std::max(Max, R - L + 1);
      } else {
        while (IntervalCharCount.size() > 2) {
          if (--IntervalCharCount[S[L]] == 0) {
            IntervalCharCount.erase(S[L]);
          }
          ++L;
        }
      }
    }
    return Max;
  }
};
