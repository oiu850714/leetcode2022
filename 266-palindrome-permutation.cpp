#include "headers.hpp"

class Solution {
public:
  bool canPermutePalindrome(const std::string &S) {
    std::vector<int> CharCount(26);
    for (auto C : S) {
      CharCount[C - 'a']++;
    }
    int CharWithOddOccurence = 0;
    for (auto Count : CharCount) {
      CharWithOddOccurence += Count & 1;
    }
    return CharWithOddOccurence <= 1;
  }
};
