#include "headers.hpp"

class Solution {
public:
  ListNode *removeElements(ListNode *Head, int Value) {
    auto Curr = &Head;
    while (*Curr) {
      if ((*Curr)->val == Value) {
        auto Removed = *Curr;
        *Curr = (*Curr)->next;
        delete Removed;
      } else {
        Curr = &(*Curr)->next;
      }
    }
    return Head;
  }
};