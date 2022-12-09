#include "headers.hpp"

class Solution {
public:
  int nthUglyNumber(int N) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> Heap;
    Heap.push(1);
    std::unordered_set<int> PushedVals{1};
    int CurrTopOrder = 0;
    int Val = 0;
    while (
        CurrTopOrder < N &&
        !Heap.empty()) { // The heap alway nonempty for all test cases though.
      Val = Heap.top();
      Heap.pop();
      ++CurrTopOrder;
      if (Val <= std::numeric_limits<int>::max() / 2 &&
          !PushedVals.count(Val * 2)) {
        Heap.push(Val * 2);
        PushedVals.insert(Val * 2);
      }
      if (Val <= std::numeric_limits<int>::max() / 3 &&
          !PushedVals.count(Val * 3)) {
        Heap.push(Val * 3);
        PushedVals.insert(Val * 3);
      }
      if (Val <= std::numeric_limits<int>::max() / 5 &&
          !PushedVals.count(Val * 5)) {
        Heap.push(Val * 5);
        PushedVals.insert(Val * 5);
      }
    }
    return Val;
  }
};
