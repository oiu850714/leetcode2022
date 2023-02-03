#include "headers.hpp"

class Solution {
public:
  bool isOneEditDistance(const std::string &S, const std::string &T) {
    if (std::abs((int)(S.size() - T.size())) >= 2) {
      return false;
    }

    // Case of replacing
    if (S.size() == T.size()) {
      int DiffChars = 0;
      for (size_t i = 0; i < S.size(); i++) {
        DiffChars += S[i] != T[i];
      }
      return DiffChars == 1;
    }

    // Case of insertion
    auto &Short = S.size() < T.size() ? S : T;
    auto &Long = S.size() < T.size() ? T : S;
    bool FoundDiff = false;
    for (size_t i = 0, j = 0; i < Long.size();) {
      if (Long[i] == Short[j]) {
        i++, j++;
        continue;
      }
      if (FoundDiff == true) {
        return false;
      } else {
        i++;
        FoundDiff = true;
      }
    }

    return true;
  }
};
