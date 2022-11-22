#include "headers.hpp"

class Solution {
public:
  std::string reverseWords(std::string S) {
    std::vector<std::string> Words;
    for (auto Beg = S.find_first_not_of(" "), End = S.find_first_of(" ", Beg);
         ;) {
      if (Beg == std::string::npos) {
        break;
      }
      Words.push_back(S.substr(Beg, End - Beg));
      Beg = S.find_first_not_of(" ", End);
      End = S.find_first_of(" ", Beg);
    }
    std::reverse(Words.begin(), Words.end());
    std::string Ret;
    for (auto &Word : Words) {
      Ret += std::move(Word) + " ";
    }
    Ret.pop_back();
    return Ret;
  }
};
