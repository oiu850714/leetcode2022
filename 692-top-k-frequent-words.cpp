#include "headers.hpp"

class Solution {
public:
  std::vector<std::string> topKFrequent(std::vector<std::string> &Words,
                                        int K) {
    std::priority_queue Heap(std::greater(),
                             buildWordNegativeCountVector(Words));
    std::vector<std::string> Ret;
    while (K-- > 0) {
      Ret.push_back(Heap.top().second);
      Heap.pop();
    }
    return Ret;
  }

private:
  std::vector<std::pair<int, std::string>>
  buildWordNegativeCountVector(const std::vector<std::string> &Words) {
    std::unordered_map<std::string, int> WordCount;
    for (const auto &Word : Words) {
      WordCount[Word]++;
    }
    std::vector<std::pair<int, std::string>> WordCountVector;
    for (auto &[Word, Count] : WordCount) {
      // Note that the count is inserted as negative.
      // The purpose is to make the heap in the call a "min"-heap that
      // essentially store the most-frequent word at the root, but compare the
      // word according to the lexical order.
      WordCountVector.push_back({-Count, Word});
    }
    return WordCountVector;
  }
};