#include "headers.hpp"

class Solution {
public:
  ListNode *rotateRight(ListNode *OldHead, int K) {
    // Empty list
    if (OldHead == nullptr) {
      return OldHead;
    }
    // Nonempty list, Len != 0.
    auto Len = getLength_(OldHead);
    K = K % Len;
    if (K == 0) {
      // Rotation has no effect.
      return OldHead;
    }

    auto NewTail = &OldHead;
    for (int i = 0; i < Len - K; ++i) {
      NewTail = &(*NewTail)->next;
    }
    auto NewHead = *NewTail;
    auto RotatedTail = NewTail;
    while (*RotatedTail) {
      RotatedTail = &(*RotatedTail)->next;
    }
    *NewTail = nullptr;
    *RotatedTail = OldHead;
    return NewHead;
  }

private:
  int getLength_(ListNode *OldHead) {
    auto Ret = 0;
    while (OldHead) {
      OldHead = OldHead->next;
      Ret++;
    }
    return Ret;
  }
};