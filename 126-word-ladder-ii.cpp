#include "headers.hpp"

using SeqTy = std::vector<std::string>;
using WordSetTy = std::unordered_set<std::string>;
using ReachingWordsTy =
    std::unordered_map<std::string, std::vector<std::string>>;
using WordStepsTy = std::unordered_map<std::string, int>;

class Solution {
public:
  std::vector<SeqTy> findLadders(std::string BeginWord, std::string EndWord,
                                 std::vector<std::string> &WordList) {
    assert(!WordList.empty());
    WordSetTy WordSet(WordList.begin(), WordList.end());
    // The concept of the implementation is to find ALL possible shortest paths
    // from BeginWord to EndWord. Refer to:
    // https://stackoverflow.com/questions/20257227/how-to-find-all-shortest-paths
    // https://stackoverflow.com/questions/14144071/finding-all-the-shortest-paths-between-two-nodes-in-unweighted-undirected-graph
    WordSetTy Visited;
    ReachingWordsTy ReachingWords;
    WordStepsTy WordSteps;

    std::vector<std::string> Queue;
    Queue.push_back(BeginWord);
    WordSteps[BeginWord] = 0;
    while (!Queue.empty()) {
      std::vector<std::string> NextQueue;
      for (auto &Word : Queue) {
        // Enumerate all possible adjacent words.
        auto AdjacentWord = Word;
        for (auto &C : AdjacentWord) {
          auto OldC = C;
          for (char NewC = 'a'; NewC <= 'z'; NewC++) {
            if (NewC == OldC) {
              continue;
            }
            C = NewC;
            if (!WordSet.count(AdjacentWord)) {
              // This adjacent word is not in the input.
              continue;
            }
            if (!Visited.count(AdjacentWord)) {
              // This adjacent word is not yet visited.
              NextQueue.push_back(AdjacentWord);
              Visited.insert(AdjacentWord);
              WordSteps[AdjacentWord] = WordSteps[Word] + 1;
              ReachingWords[AdjacentWord].push_back(Word);
            } else {
              if (WordSteps[AdjacentWord] == WordSteps[Word] + 1) {
                ReachingWords[AdjacentWord].push_back(Word);
              }
            }
          }
          C = OldC;
        }
      }
      Queue.swap(NextQueue);
    }

    if (!WordSteps.count(EndWord)) {
      return {};
    }
    return buildSeqs_(ReachingWords, BeginWord, EndWord);
  }

private:
  // Assume we can really go from BeginWord to EndWord.
  // Then the various of the corresponding word set must be successful.
  std::vector<SeqTy> buildSeqs_(const ReachingWordsTy &ReachingWords,
                                const std::string &BeginWord,
                                const std::string &CurrWord) {
    if (CurrWord == BeginWord) {
      return {{BeginWord}};
    }

    std::vector<SeqTy> Ret;
    for (auto &Parent : ReachingWords.at(CurrWord)) {
      auto SubSeqs = buildSeqs_(ReachingWords, BeginWord, Parent);
      for (auto &Sub : SubSeqs) {
        Sub.push_back(CurrWord);
        Ret.push_back(Sub);
      }
    }
    return Ret;
  }
};
