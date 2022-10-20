#include "headers.hpp"

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *HeadA, ListNode *HeadB) {
    auto LenA = getLength(HeadA), LenB = getLength(HeadB);
    if (LenA < LenB) {
      // Try to make the the first list longer.
      std::swap(HeadA, HeadB);
      std::swap(LenA, LenB);
    }

    auto HeadAPtr = getNthNode(HeadA, LenA - LenB);
    auto HeadBPtr = HeadB;
    while (HeadAPtr && HeadBPtr && HeadAPtr != HeadBPtr) {
      HeadAPtr = HeadAPtr->next;
      HeadBPtr = HeadBPtr->next;
    }
    return HeadAPtr;
  }

private:
  int getLength(ListNode *Head) {
    auto Ret = 0;
    while (Head) {
      Head = Head->next;
      Ret++;
    }
    return Ret;
  }
  ListNode *getNthNode(ListNode *Head, int N) {
    while (N--) {
      Head = Head->next;
    }
    return Head;
  }
};