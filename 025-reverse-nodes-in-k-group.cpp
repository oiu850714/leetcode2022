#include "headers.hpp"

class Solution {
public:
  // Related problem: 206.
  ListNode *reverseKGroup(ListNode *Head, int K) {
    if (K == 1) {
      // Useless base case.
      return Head;
    }

    ListNode **KBegin = &Head, **KEnd = nullptr;
    while (KEnd = getKNodesAfter_(KBegin, K)) {
      // Temporarily cut this new found k-nodes list.
      auto NextPartBegin = *KEnd;
      *KEnd = nullptr;

      // Reverse this new found list.
      auto [ReversedHead, ReversedTail] = reverseListIterative_(*KBegin);

      // Paste the reversed list back to the corresponding position of the
      // original list.
      *KBegin = ReversedHead;
      *ReversedTail = NextPartBegin;

      // Move the Beginning of the next part; note that the beginning of the
      // next part is the reversed list's tail.
      KBegin = ReversedTail;
    }

    return Head;
  }

  ListNode **getKNodesAfter_(ListNode **KBegin, int K) {
    auto Ret = KBegin;
    while (K > 0 && *Ret) {
      Ret = &(*Ret)->next;
      K--;
    }
    if (K > 0) {
      // The list has less than K nodes.
      return nullptr;
    } else {
      return Ret;
    }
  }

  // Copied from 206.; either recursive or iterative is OK.
  // But use iterative to make space truely O(1).
  // Return Head and (address of) tail's next.
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
