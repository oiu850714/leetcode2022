#include "headers.hpp"

class Solution {
public:
  ListNode *insertionSortList(ListNode *Head) {
    ListNode *Sorted = nullptr;
    while (Head) {
      auto Cutted = Head;
      Head = Head->next;
      Cutted->next = Head;

      auto P = &Sorted;
      while (*P && (*P)->val < Cutted->val) {
        P = &(*P)->next;
      }
      Cutted->next = *P;
      *P = Cutted;
    }
    return Sorted;
  }
};
