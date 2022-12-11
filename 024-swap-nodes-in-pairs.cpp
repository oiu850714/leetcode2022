#include "headers.hpp"

class Solution {
public:
  ListNode *swapPairs(ListNode *Head) {
    swapPairsRecursive_(&Head);
    return Head;
  }

private:
  void swapPairsRecursive_(ListNode **Head) {
    if (!*Head || !(*Head)->next) {
      return;
    }
    auto Curr = *Head, Next = (*Head)->next, NextNext = (*Head)->next->next;
    *Head = Next;
    Next->next = Curr;
    Curr->next = NextNext;
    swapPairsRecursive_(&(*Head)->next->next);
  }
};
