#include "headers.hpp"

class Solution {
public:
  int ladderLength(std::string BeginWord, std::string EndWord,
                   std::vector<std::string> &WordList) {
    std::unordered_set<std::string> WordSet(WordList.begin(), WordList.end());

    // Just a base case.
    if (!WordSet.count(EndWord)) {
      return 0;
    }

    std::vector<std::string> OldQueue;
    int Steps = 1;
    OldQueue.push_back(BeginWord);
    while (!OldQueue.empty()) {
      decltype(OldQueue) NewQueue;
      for (auto &Word : OldQueue) {
        if (Word == EndWord) {
          return Steps;
        }

        // Enumerate all possible adjacent words.
        auto AdjacentWord = Word;
        for (auto &C : AdjacentWord) {
          auto OldC = C;
          for (auto NewC : "abcdefghijklmnopqrstuvwxyz") {
            if (NewC == OldC) {
              continue;
            }
            C = NewC;
            if (WordSet.count(AdjacentWord)) {
              NewQueue.push_back(AdjacentWord);
              WordSet.erase(AdjacentWord);
            }
          }
          C = OldC;
        }
      }
      Steps += 1;
      OldQueue.swap(NewQueue);
    }
    return 0;
  }
};
