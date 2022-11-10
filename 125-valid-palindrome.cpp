#include "headers.hpp"

class Solution {
public:
  bool isPalindrome(const std::string &S) {
    std::string FilteredS;
    for (auto c : S) {
      if (std::isdigit(c)) {
        FilteredS.push_back(c);
      } else if (std::isalpha(c)) {
        FilteredS.push_back(std::tolower(c));
      }
    }

    int Beg = 0, End = FilteredS.size() - 1;

    // Note that "<" considers the case that FilteredS is empty.
    while (Beg < End) {
      if (FilteredS[Beg++] != FilteredS[End--]) {
        return false;
      }
    }
    return true;
  }
};