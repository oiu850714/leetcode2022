#include "headers.hpp"
class Solution {
public:
  int characterReplacement(std::string S, int K) {
    // Use the assumption that S consists of only uppercase English letters.
    std::vector<int> CharCnt(26);
    int MaxLength = 0;
    // Try to make the window bound as half-closed: [LBound, RBound)
    // But that will make RBound point to the position "after" the last
    // character of S, i.e. S[S.size()]
    for (int LBound = 0, RBound = 1; RBound < S.size() + 1; RBound += 1) {
      CharCnt[S[RBound - 1] - 'A'] += 1;
      if ((RBound - LBound) -
              *std::max_element(CharCnt.begin(), CharCnt.end()) <=
          K) {
        MaxLength = std::max(MaxLength, RBound - LBound);
      } else {
        // Shift the LBound until the window is valid again.
        do {
          CharCnt[S[LBound] - 'A'] -= 1;
          LBound += 1;
        } while ((RBound - LBound) -
                     *std::max_element(CharCnt.begin(), CharCnt.end()) >
                 K);
      }
    }
    return MaxLength;
  }
};