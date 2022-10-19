#include "headers.hpp"

class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    auto sIter = s.begin(), tIter = t.begin();
    while (sIter != s.end() && tIter != t.end()) {
      if (*sIter == *tIter) {
        ++sIter;
      }
      ++tIter;
    }
    return sIter == s.end();
  }
};