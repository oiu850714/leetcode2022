#include "headers.hpp"

class Solution {
public:
  int longestPalindrome(std::vector<std::string> &Words) {
    std::unordered_map<std::string, int> WordCount;
    for (const auto &Word : Words) {
      WordCount[Word]++;
    }
    bool HasMiddleUsed = false;
    int MaxLength = 0;
    while (!WordCount.empty()) {
      auto &[Word, Count] = *WordCount.begin();
      // We always pick the word and discard it; decrement the count to make the
      // code simpler.
      Count--;
      // e.g. Word = "xx".
      if (Word[0] == Word[1]) {
        if (WordCount.at(Word) >= 1) {
          // There is still at least one such word, so we use that same word
          // again.
          MaxLength += 4;
          Count--;
        } else {
          if (!HasMiddleUsed) {
            // We can put this word in the middle of the palindrome.
            HasMiddleUsed = true;
            MaxLength += 2;
          }
        }
      } else {
        std::string ReverseWord = {Word[1], Word[0]};
        if (WordCount.find(ReverseWord) != WordCount.end() &&
            WordCount.at(ReverseWord) > 0) {
          MaxLength += 4;
          WordCount.at(ReverseWord)--;
          if (WordCount.at(ReverseWord) == 0) {
            WordCount.erase(ReverseWord);
          }
        }
      }
      if (Count == 0) {
        WordCount.erase(Word);
      }
    }
    return MaxLength;
  }
};