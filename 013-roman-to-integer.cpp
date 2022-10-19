#include "headers.hpp"

class Solution {
public:
  int romanToInt(std::string S) {
    // Assume S is valid representation.
    std::map<char, int> SymbolValueMapping{
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };
    int Ret = 0;
    for (int i = 0; i < S.size(); i++) {
      if (i == S.size() - 1) {
        // S[i] is the last character, we can directly increment Ret by the
        // integer value corresponding to S[i].
        Ret += SymbolValueMapping[S[i]];
        continue;
      }

      if (SymbolValueMapping[S[i]] >= SymbolValueMapping[S[i + 1]]) {
        Ret += SymbolValueMapping[S[i]];
      } else {
        // The special cases where the roman literal is (legally) reversed.
        Ret -= SymbolValueMapping[S[i]];
      }
    }
    return Ret;
  }
};