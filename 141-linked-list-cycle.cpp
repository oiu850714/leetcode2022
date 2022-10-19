#include "headers.hpp"

class Solution {
public:
  bool hasCycle(ListNode *Head) {
    // Tortoise and Hare Algo.
    auto FastPtr = Head, SlowPtr = Head;
    while (FastPtr) {
      FastPtr = FastPtr->next;
      if (!FastPtr) {
        // encounter tail
        return false;
      }
      SlowPtr = SlowPtr->next;
      FastPtr = FastPtr->next;
      if (FastPtr == SlowPtr) {
        return true;
      }
    }
    return false;
  }
};