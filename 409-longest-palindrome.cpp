#include "headers.hpp"

class Solution {
public:
  int longestPalindrome(std::string S) {
    std::map<std::remove_reference_t<decltype(S.front())>, int> CharQuota;
    for (auto c : S) {
      ++CharQuota[c];
    }
    bool SingleMiddleFlag = false;
    int MaxPrefixLength = 0;
    for (auto [Char, Count] : CharQuota) {
      MaxPrefixLength += (Count / 2);
      if (Count % 2 && !SingleMiddleFlag) {
        SingleMiddleFlag = true;
      }
    }
    return SingleMiddleFlag ? MaxPrefixLength * 2 + 1 : MaxPrefixLength * 2;
  }
};