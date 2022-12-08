#include "headers.hpp"

class Solution {
public:
  ListNode *reverseBetween(ListNode *Head, int LeftIdx, int RightIdx) {
    // Assume LeftIdx and RightIdx are valid.

    // There is only one node in the interval.
    if (LeftIdx == RightIdx) {
      return Head;
    }

    // Convert the interval to:
    // 1. [LeftIdx, RightIdx)
    // 2. 0-based.
    RightIdx++;
    --LeftIdx, --RightIdx;

    // Find the to-be-reversed sublist.
    auto Diff = RightIdx - LeftIdx;
    auto SubBeg = &Head;
    while (LeftIdx--) {
      SubBeg = &(*SubBeg)->next;
    }
    auto SubEnd = SubBeg;
    while (Diff--) {
      SubEnd = &(*SubEnd)->next;
    }

    // Cut the sublist.
    auto OldRightTail = *SubEnd;
    *SubEnd = nullptr;

    // Reverse the sublist and paste it back.
    auto [ReversedLeft, TailNext] = reverseListIterative_(*SubBeg);
    *SubBeg = ReversedLeft;
    *TailNext = OldRightTail;
    return Head;
  }

private:
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
