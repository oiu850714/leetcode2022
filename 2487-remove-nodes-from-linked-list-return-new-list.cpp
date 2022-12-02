#include "headers.hpp"

class Solution {
public:
  ListNode *removeNodes(ListNode *Head) {
    std::stack<int> MonoStack;
    while (Head) {
      while (!MonoStack.empty() && MonoStack.top() < Head->val) {
        MonoStack.pop();
      }
      MonoStack.push(Head->val);
      Head = Head->next;
    }

    deleteList_(Head);

    ListNode *Ret = nullptr;
    while (!MonoStack.empty()) {
      auto NewHead = new ListNode(MonoStack.top());
      NewHead->next = Ret;
      Ret = NewHead;
      MonoStack.pop();
    }
    return Ret;
  }

private:
  void deleteList_(ListNode *Head) {
    while (Head) {
      auto Old = Head;
      Head = Head->next;
      delete Old;
    }
  }
};
