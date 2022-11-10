#include "headers.hpp"

class Solution {
public:
  bool isAnagram(std::string S, std::string T) {
    if (S.size() != T.size()) {
      return false;
    }
    std::unordered_map<char, int> SWordCount;
    for (auto C : S) {
      SWordCount[C]++;
    }
    for (auto C : T) {
      if (!SWordCount.count(C)) {
        // S does not contain the character C.
        return false;
      }
      if (SWordCount.at(C) == 0) {
        // All characters C in S have run out.
        return false;
      }
      SWordCount.at(C)--;
    }
    return true;
  }
};