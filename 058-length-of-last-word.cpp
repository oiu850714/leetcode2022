#include "headers.hpp"

class Solution {
public:
  int lengthOfLastWord(std::string S) {
    auto firstNonSpace =
        std::find_if(S.crbegin(), S.crend(), [](auto c) { return c != ' '; });
    return std::find_if(firstNonSpace, S.crend(),
                        [](auto c) { return c == ' '; }) -
           firstNonSpace;
  }
};