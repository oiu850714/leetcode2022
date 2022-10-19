#include "headers.hpp"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *Head, int N) {
    // Assume 1 <= N <= the size of the list, so the N-th node is valid.
    auto NthNodeAfterCurrent = getNthNode(Head, N);
    auto Current = &Head;

    // After the loop, Current will point to the pointer in the
    // list such that the pointer points to the to-be-deleted node.
    while (NthNodeAfterCurrent) {
      Current = &(*Current)->next;
      NthNodeAfterCurrent = NthNodeAfterCurrent->next;
    }
    // Get the node after the to-be-deleted-node.
    auto NewNext = (*Current)->next;
    // Delete the to-be-deleted-node.
    delete *Current;
    // Make the pointer that originally pointed to the to-be-deleted-node point
    // to the node after the to-be-deleted-node.
    *Current = NewNext;
    return Head;
  }

private:
  ListNode *getNthNode(ListNode *Head, int N) {
    while (N--) {
      Head = Head->next;
    }
    return Head;
  }
};