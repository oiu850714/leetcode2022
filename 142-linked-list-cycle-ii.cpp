#include "headers.hpp"

class Solution {
public:
  ListNode *detectCycle(ListNode *Head) {
    auto FastPtr = Head, SlowPtr = Head;
    while (FastPtr) {
      FastPtr = FastPtr->next;
      if (!FastPtr) {
        // encounter tail
        return nullptr;
      }
      SlowPtr = SlowPtr->next;
      FastPtr = FastPtr->next;
      if (FastPtr == SlowPtr) {
        return calCycleStart(Head, FastPtr);
      }
    }
    return nullptr;
  }

private:
  // FastPtr is in the position at which it encounters with slow pointer
  // By some arguments, we can conclude that by advancing FastPtr and Head,
  // respectively, they will encounter at the cycle start position.
  ListNode *calCycleStart(ListNode *Head, ListNode *FastPtr) {
    while (Head != FastPtr) {
      Head = Head->next;
      FastPtr = FastPtr->next;
    }
    return Head;
  }
};