#include "headers.hpp"
#include <sstream>

class Solution {
public:
  std::string toGoatLatin(std::string Sentence) {
    auto Words = toWords_(std::move(Sentence));
    constexpr std::array Vowels{'a', 'e', 'i', 'o', 'u'};
    std::string Suffix_a = "a";
    for (auto &Word : Words) {
      if (std::find(Vowels.begin(), Vowels.end(), std::tolower(Word[0])) ==
          Vowels.end()) {
        std::rotate(Word.begin(), Word.begin() + 1, Word.end());
      }
      Word += "ma" + Suffix_a;
      Suffix_a.push_back('a');
    }
    std::string Ret = std::move(Words[0]);
    for (int i = 1; i < Words.size(); i++) {
      Ret += " " + std::move(Words[i]);
    }
    return Ret;
  }

private:
  std::vector<std::string> toWords_(std::string Sentence) {
    std::vector<std::string> Words;
    std::istringstream ISS(std::move(Sentence));
    for (std::string Word; ISS >> Word;) {
      Words.push_back(std::move(Word));
    }
    return Words;
  }
};
