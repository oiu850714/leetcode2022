#include "headers.hpp"

class Solution {
public:
  std::string longestPalindrome(std::string S) {
    // Assume S has size at least 1.
    // Just first check edge cases to make the DP below more simple.
    if (S.size() == 1) {
      return S;
    }
    if (S.size() == 2) {
      return S[0] == S[1] ? S : S.substr(1);
    }

    // The i,j entry of DP table stores whether S[i, j] is a palindrome.
    // Note that now the interval is NOT half-open; it's contains j-th character
    // inclusive.
    std::vector<std::vector<bool>> DPTable(S.size(),
                                           std::vector<bool>(S.size()));
    int MaxLength = 1;
    int MaxStart = 0;
    // Set base cases for DPTable: S[i, i]'s and S[i, i + 1]'s
    for (int i = 0; i < S.size() - 1; i++) {
      DPTable[i][i] = true;
      DPTable[i][i + 1] = S[i] == S[i + 1];
      if (DPTable[i][i + 1]) {
        // There may be the cases that the substring with length 2 is a
        // palindrome.
        MaxLength = 2;
        MaxStart = i;
      }
    }
    DPTable[S.size() - 1][S.size() - 1] = true;

    for (int SubStrSize = 3; SubStrSize <= S.size(); SubStrSize++) {
      for (int SubStrStart = 0; SubStrStart + SubStrSize - 1 < S.size();
           SubStrStart++) {
        auto SubStrEnd = SubStrStart + SubStrSize - 1;
        // Note that the -1 offset by the second index; it's because the
        // interval of the substring is both closed at the two end.
        DPTable[SubStrStart][SubStrEnd] =
            DPTable[SubStrStart + 1][SubStrEnd - 1] &&
            (S[SubStrStart] == S[SubStrEnd]);
        // Whether S[i, j] is a palindrome depends on
        // 1. S[i + 1, j - 1] is a palindrome
        // 2. S[i] == S[j]
        if (DPTable[SubStrStart][SubStrEnd] && SubStrSize > MaxLength) {
          MaxLength = SubStrSize;
          MaxStart = SubStrStart;
        }
      }
    }
    return S.substr(MaxStart, MaxLength);
  }
};