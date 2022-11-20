#include "headers.hpp"

using ReturnTy = std::vector<std::vector<std::string>>;
using SequenceTy = std::vector<std::string>;
using WordSetTy = std::unordered_set<std::string>;
using WordParentsTy = std::unordered_map<std::string, std::vector<std::string>>;
using WordStepsTy = std::unordered_map<std::string, int>;

class Solution {
public:
  ReturnTy findLadders(std::string BeginWord, std::string EndWord,
                       std::vector<std::string> &WordList) {
    WordSetTy WordSet(WordList.begin(), WordList.end());
    // Just a base case.
    if (!WordSet.count(EndWord)) {
      return {};
    }

    // The concept of the implementation is to find ALL possible shortest paths
    // from BeginWord to EndWord.
    // Refer to:
    // https://stackoverflow.com/questions/20257227/how-to-find-all-shortest-paths
    // https://stackoverflow.com/questions/14144071/finding-all-the-shortest-paths-between-two-nodes-in-unweighted-undirected-graph
    WordSetTy VisitedWords;
    WordParentsTy WordParents;
    WordStepsTy WordSteps;

    std::vector<std::string> Queue;
    Queue.push_back(BeginWord);
    WordSteps[BeginWord] = 1;
    bool FindWord = false;
    while (!Queue.empty()) {
      std::vector<std::string> NextQueue;
      for (auto &Word : Queue) {
        if (Word == EndWord) {
          FindWord = true;
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
            if (!WordSet.count(AdjacentWord)) {
              // This adjacent word is not in the input.
              continue;
            }
            if (!VisitedWords.count(AdjacentWord)) {
              // This adjacent word is not yet visited.
              NextQueue.push_back(AdjacentWord);
              VisitedWords.insert(AdjacentWord);
              WordSteps[AdjacentWord] = WordSteps[Word] + 1;
              WordParents[AdjacentWord].push_back(Word);
            } else {
              if (WordSteps[AdjacentWord] == WordSteps[Word] + 1) {
                WordParents[AdjacentWord].push_back(Word);
              }
            }
          }
          C = OldC;
        }
      }
      Queue.swap(NextQueue);
    }

    if (!FindWord) {
      return {};
    }
    auto ReverseSeqs = buildReverseSeqs_(WordParents, BeginWord, EndWord);
    for (auto &ReverseSeq : ReverseSeqs) {
      std::reverse(ReverseSeqs.begin(), ReverseSeqs.end());
    }
    return ReverseSeqs;
  }

private:
  // Assume we can really go from BeginWord to EndWord.
  // Then the various of the corresponding word set must be successful.
  ReturnTy buildReverseSeqs_(const WordParentsTy &WordParents,
                             const std::string &BeginWord,
                             const std::string &CurrWord) {
    if (CurrWord == BeginWord) {
      return {{BeginWord}};
    }

    ReturnTy Ret;
    for (auto &Parent : WordParents.at(CurrWord)) {
      auto SubSeqs = buildReverseSeqs_(WordParents, BeginWord, Parent);
      for (auto &Sub : SubSeqs) {
        Sub.push_back(CurrWord);
        Ret.push_back(Sub);
      }
    }
    return Ret;
  }
};
