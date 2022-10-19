#include "headers.hpp"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *Head) {
    // There is no need to use double pointer, because a to-be-deleted node is
    // never be the Head node.
    auto Curr = Head;
    while (Curr != nullptr && Curr->next != nullptr) {
      if (Curr->val == Curr->next->val) {
        auto ToBeDeleted = Curr->next;
        Curr->next = ToBeDeleted->next;
        delete ToBeDeleted;
      } else {
        Curr = Curr->next;
      }
    }
    return Head;
  }
};