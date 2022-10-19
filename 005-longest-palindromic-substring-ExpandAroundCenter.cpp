#include "headers.hpp"

class Solution {
public:
  std::string longestPalindrome(std::string S) {
    int MaxLength = 1, MaxStart = 0;
    for (int i = 0; i < S.size(); i++) {
      // The case where the center is in a character S[i]
      // It will check S[i - 1] and S[i + 1], S[i - 2] and S[i + 2], etc, until
      // the S[i - j] and S[i + j] are not equal for some j
      for (int j = 0; i - j >= 0; j++) {
        if (S[i - j] != S[i + j]) {
          break;
        }
        if (2 * j + 1 > MaxLength) {
          MaxLength = 2 * j + 1;
          MaxStart = i - j;
        }
      }
      // The case where the center is between two characters S[i] and S[i + 1].
      // It will check S[i] and S[i + 1], S[i - 1] and S[i + 2], etc,
      // until the S[i - j] and S[i + j + 1] are not equal for some j
      for (int j = 0; i - j >= 0; j++) {
        if (S[i - j] != S[i + j + 1]) {
          break;
        }
        if (2 * j + 2 > MaxLength) {
          MaxLength = 2 * j + 2;
          MaxStart = i - j;
        }
      }
    }
    return S.substr(MaxStart, MaxLength);
  }
};