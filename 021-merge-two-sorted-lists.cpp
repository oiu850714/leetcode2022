#include "headers.hpp"

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *List1, ListNode *List2) {
    ListNode *Ret = nullptr;
    auto Curr = &Ret;
    while (List1 != nullptr && List2 != nullptr) {
      if (List1->val <= List2->val) {
        *Curr = List1;
        Curr = &List1->next;
        List1 = List1->next;
      } else {
        *Curr = List2;
        Curr = &List2->next;
        List2 = List2->next;
      }
    }

    // Concate remaining nodes
    *Curr = List1 != nullptr ? List1 : List2;

    return Ret;
  }
};