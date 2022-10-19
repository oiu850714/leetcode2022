#include "headers.hpp"

class Solution {
public:
  ListNode *oddEvenList(ListNode *Head) {
    // The list with at most 2 nodes can be left untouched since they are
    // already "odd-even" by definition. And dealing with these cases in the
    // general case is somewhat annoying.
    if (!Head || !Head->next) {
      return Head;
    }

    // The invariant is to partition the list into three parts:
    // 1. The odd part, 2. The even part, 3. The unprocessed part.
    // And the EvenHead and UnprocessedHead point to the (pointer of) 2. and 3.,
    // respectively.
    auto EvenHead = &Head->next, UnprocessedHead = &Head->next->next;
    // We can directly start from the third node(if exists) since the first two
    // nodes are already in the correct position.
    auto Counter = 3;
    while (*UnprocessedHead) {
      if (Counter % 2 == 0) {
        // The current unprocessed node is an even-th node.
        // Only need to increment the unprocessed pointer
        UnprocessedHead = &(*UnprocessedHead)->next;
      } else {
        // The current unprocessed node is an odd-th node.
        // Below is just some messy detail for moving the odd node to the
        // position before the even part of the list, and update the EvenHead
        // accordingly.
        auto NewOddNode = *UnprocessedHead;
        *UnprocessedHead = NewOddNode->next;
        NewOddNode->next = *EvenHead;
        *EvenHead = NewOddNode;
        EvenHead = &NewOddNode->next;
      }
      Counter++;
    }
    return Head;
  }
};