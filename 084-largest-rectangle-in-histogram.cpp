#include "headers.hpp"

class Solution {
public:
  int largestRectangleArea(std::vector<int> &Heights) {
    auto NextSmallerHeight = nextSmallerHeights_(Heights);
    auto PrevSmallerHeight = prevSmallerHeights_(Heights);

    int Ret = 0;
    for (int i = 0; i < Heights.size(); i++) {
      Ret = std::max(
          Ret, ((NextSmallerHeight[i] - i) + (i - PrevSmallerHeight[i]) - 1) *
                   Heights[i]);
    }
    return Ret;
  }

  std::vector<int> nextSmallerHeights_(const std::vector<int> &Heights) {
    std::vector<int> Ret(Heights.size(), Heights.size());

    std::stack<int> MonoStack;
    for (int i = 0; i < Heights.size(); i++) {
      while (!MonoStack.empty() && Heights[i] < Heights[MonoStack.top()]) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }

  std::vector<int> prevSmallerHeights_(const std::vector<int> &Heights) {
    std::vector<int> Ret(Heights.size(), -1);

    std::stack<int> MonoStack;
    for (int i = Heights.size() - 1; i >= 0; i--) {
      while (!MonoStack.empty() && Heights[i] < Heights[MonoStack.top()]) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }
};
