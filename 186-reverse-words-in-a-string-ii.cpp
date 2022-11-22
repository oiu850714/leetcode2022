#include "headers.hpp"

class Solution {
public:
  void reverseWords(std::vector<char> &S) {
    // The concept is the same as 189.
    std::reverse(S.begin(), S.end());
    for (auto Beg = S.begin(), End = std::find(Beg, S.end(), ' ');;) {
      std::reverse(Beg, End);
      if (End == S.end()) {
        return;
      }
      Beg = End + 1;
      End = std::find(Beg, S.end(), ' ');
    }
  }
};