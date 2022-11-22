#include "headers.hpp"

class Solution {
public:
  // Related problem: 25., 206.
  // Just slightly adapted(i.e. COPIED) from 25.
  ListNode *reverseEvenLengthGroups(ListNode *Head) {
    int GroupSize = 1;

    ListNode **KBegin = &Head, **KEnd = nullptr;
    int ActualSize = 0;
    while (KEnd = getNumNodesAfter_(KBegin, GroupSize++, &ActualSize)) {
      // The new list is empty.
      if (KBegin == KEnd) {
        break;
      }

      // List of odd nodes.
      if (ActualSize & 1 == 1) {
        KBegin = KEnd;
        continue;
      }

      auto NextPartBegin = *KEnd;
      *KEnd = nullptr;

      auto [ReversedHead, ReversedTail] = reverseListIterative_(*KBegin);
      *KBegin = ReversedHead;

      *ReversedTail = NextPartBegin;

      KBegin = ReversedTail;
    }

    return Head;
  }

  ListNode **getNumNodesAfter_(ListNode **KBegin, int Num, int *ActualSize) {
    *ActualSize = Num;
    auto Ret = KBegin;
    while (Num > 0 && *Ret) {
      Ret = &(*Ret)->next;
      Num--;
    }
    *ActualSize -= Num;
    return Ret;
  }

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
