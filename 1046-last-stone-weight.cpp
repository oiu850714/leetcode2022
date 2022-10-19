#include "headers.hpp"

class Solution {
public:
  int lastStoneWeight(std::vector<int> &Stones) {
    std::priority_queue<int> Heap(Stones.begin(), Stones.end());
    while (Heap.size() >= 2) {
      auto Stone1 = Heap.top();
      Heap.pop();
      auto Stone2 = Heap.top();
      Heap.pop();
      if (Stone1 == Stone2) {
        continue;
      } else {
        Heap.push(std::abs(Stone1 - Stone2));
      }
    }
    if (Heap.empty()) {
      return 0;
    } else {
      return Heap.top();
    }
  }
};