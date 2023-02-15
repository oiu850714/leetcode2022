#include "headers.hpp"

class Solution {
public:
  int countSubstrings(std::string S) {
    // Just use 005.'s "expand around" algo.
    int Ret = 0;
    for (int i = 0; i < S.size(); i++) {
      // Odd len substring.
      for (int j = 0; i - j >= 0 && i + j < S.size(); j++) {
        if (S[i - j] == S[i + j]) {
          Ret += 1;
        } else {
          break;
        }
      }

      // Even len substring.
      for (int j = 0; i - j >= 0 && i + j + 1 < S.size(); j++) {
        if (S[i - j] == S[i + j + 1]) {
          Ret += 1;
        } else {
          break;
        }
      }
    }
    return Ret;
  }
};
