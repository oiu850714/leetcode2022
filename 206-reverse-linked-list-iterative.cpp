#include "headers.hpp"

class Solution {
public:
  ListNode *reverseList(ListNode *Head) {
    if (!Head) {
      // There is testcase for empty list.
      return Head;
    }
    return reverseListIterative_(Head).first;
  }

private:
  // Return Head and (address of) tail's next.
  // Return tail just for the sake of API compatibility with my recursive
  // version.
  std::pair<ListNode *, ListNode **> reverseListIterative_(ListNode *Head) {
    auto NewTail = &Head->next;
    ListNode *Prev = nullptr, *Curr = Head;
    while (Curr) {
      auto OldPrev = Prev, OldCurr = Curr, OldNext = Curr->next;
      Prev = OldCurr;
      Curr->next = OldPrev;
      Curr = OldNext;
    }
    // Now Prev is the new head.
    return {Prev, NewTail};
  }
};
