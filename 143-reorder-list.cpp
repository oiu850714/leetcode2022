#include "headers.hpp"

class Solution {
public:
  void reorderList(ListNode *Head) {
    assert(Head);

    // Find the second part.
    // The cutting point guaranteed that if the list has even nodes, then the
    // two parts have the same #nodes. If odd, then the first part has one more
    // node.
    auto FirstTailNext = &Head;
    {
      auto FasterPtr = Head;
      while (FasterPtr) {
        FasterPtr = FasterPtr->next;
        FirstTailNext = &(*FirstTailNext)->next;
        if (FasterPtr) {
          FasterPtr = FasterPtr->next;
        }
      }
    }
    auto SecondHead = *FirstTailNext;
    if (!SecondHead) {
      // Then the whole list has only one node, return.
      return;
    }

    // Cut the second part;
    *FirstTailNext = nullptr;
    // Reverse the second part.
    SecondHead = reverseListIterative_(SecondHead).first;

    // Now alternately concatenate the nodes of the two parts.
    auto FirstCurr = Head, SecondCurr = SecondHead;
    // Since the #nodes of second part <= #nodes of first part, we only need to
    // check SecondCurr.
    while (SecondCurr) {
      auto SecondCurrNode = SecondCurr;
      SecondCurr = SecondCurr->next;
      SecondCurrNode->next = FirstCurr->next;
      FirstCurr->next = SecondCurrNode;
      FirstCurr = FirstCurr->next->next;
    }
  }

private:
  // Copied from 092.
  std::pair<ListNode *, ListNode **> reverseListIterative_(ListNode *Head) {
    assert(Head);
    auto NewTail = &Head->next;
    ListNode *ReversedPartHead = nullptr, *Curr = Head;
    while (Curr) {
      auto OldReversedPartHead = ReversedPartHead, OldCurr = Curr,
           OldNext = Curr->next;
      Curr->next = OldReversedPartHead;
      ReversedPartHead = Curr;
      Curr = OldNext;
    }
    return {ReversedPartHead, NewTail};
  }
};
