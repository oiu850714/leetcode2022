#include "headers.hpp"

class Solution {
public:
  bool halvesAreAlike(std::string S) {
    auto isVowel = [](char C) -> bool {
      const static std::string Vowels{"aeiouAEIOU"};
      return std::count(std::begin(Vowels), std::end(Vowels), C);
    };
    return std::count_if(S.begin(), S.begin() + S.size() / 2, isVowel) ==
           std::count_if(S.begin() + S.size() / 2, S.end(), isVowel);
  }
};
