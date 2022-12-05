#include "headers.hpp"

class Solution {
public:
  std::string frequencySort(std::string S) {
    std::map<char, int> CharCount;
    for (auto C : S) {
      CharCount[C]++;
    }
    std::priority_queue<std::pair<int, char>> Heap;
    for (auto [Char, Count] : CharCount) {
      Heap.push({Count, Char});
    }
    std::string Ret;
    Ret.reserve(S.size());
    while (!Heap.empty()) {
      auto [Count, Char] = Heap.top();
      Heap.pop();
      while (Count-- > 0) {
        Ret.push_back(Char);
      }
    }
    return Ret;
  }
};
