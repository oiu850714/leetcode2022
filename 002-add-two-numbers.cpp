#include "headers.hpp"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *L1, ListNode *L2) {
    ListNode *L = nullptr;
    auto Tail = &L;
    int Carry = 0;
    while (L1 || L2) {
      auto Sum = Carry;
      if (L1) {
        Sum += L1->val;
        L1 = L1->next;
      }
      if (L2) {
        Sum += L2->val;
        L2 = L2->next;
      }
      Carry = Sum / 10;
      Sum = Sum % 10;
      *Tail = new ListNode(Sum);
      Tail = &(*Tail)->next;
    }
    if (Carry) {
      *Tail = new ListNode(1);
    }
    return L;
  }
};
