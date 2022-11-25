#include "headers.hpp"

class Solution {
public:
  // Essentially the same as 496.
  std::vector<int> nextLargerNodes(ListNode *Head) {
    const int NodeCount = [Head]() mutable {
      int Ret = 0;
      while (Head) {
        Head = Head->next;
        Ret++;
      }
      return Ret;
    }();

    std::vector<int> Ret(NodeCount);

    int NodeIdx = 0;
    // NodeIdx, Node
    std::stack<std::pair<int, ListNode *>> MonoStack;
    while (Head) {
      // The condition in 496. can just be simplified as below.
      // Reserve the old code in 496. and simplified in this solution.
      while (!MonoStack.empty() && MonoStack.top().second->val < Head->val) {
        Ret[MonoStack.top().first] = Head->val;
        MonoStack.pop();
      }
      MonoStack.push({NodeIdx++, Head});
      Head = Head->next;
    }
    return Ret;
  }
};
