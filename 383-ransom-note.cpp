#include "headers.hpp"

class Solution {
public:
  bool canConstruct(std::string RansomNote, std::string Magazine) {
    std::array<int, 26> CharCount{};
    for (auto C : Magazine) {
      CharCount[C - 'a']++;
    }
    for (auto C : RansomNote) {
      if (CharCount[C - 'a'] == 0) {
        return false;
      }
      CharCount[C - 'a']--;
    }
    return true;
  }
};
