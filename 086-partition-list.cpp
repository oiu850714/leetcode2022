#include "headers.hpp"

class Solution {
public:
  ListNode *partition(ListNode *Head, int X) {
    ListNode *LessHead = nullptr, *GEHead = nullptr;
    auto Curr = Head;
    auto LessTail = &LessHead, GETail = &GEHead;
    while (Curr) {
      // Cut Curr node first.
      auto Next = Curr->next;
      Curr->next = nullptr;

      if (Curr->val < X) {
        *LessTail = Curr;
        LessTail = &Curr->next;
      } else {
        *GETail = Curr;
        GETail = &Curr->next;
      }

      Curr = Next;
    }

    *LessTail = GEHead;
    return LessHead;
  }
};
