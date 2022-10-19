#include "headers.hpp"

class Solution {
public:
  ListNode *middleNode(ListNode *Head) {
    auto Curr = Head, HeadCurrMiddle = Head;
    while (Curr) {
      Curr = Curr->next;
      if (!Curr) {
        return HeadCurrMiddle;
      }
      HeadCurrMiddle = HeadCurrMiddle->next;
      Curr = Curr->next;
    }
    return HeadCurrMiddle;
  }
};