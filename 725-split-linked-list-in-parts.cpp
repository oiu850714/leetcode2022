#include "headers.hpp"

class Solution {
public:
  std::vector<ListNode *> splitListToParts(ListNode *Head, int K) {
    decltype(splitListToParts(Head, K)) Ret;
    auto ListSize = getListSize(Head);
    auto SplittedSize = ListSize / K;
    auto NumOfListWithOneMoreElement = ListSize % K;
    while (K--) {
      ListNode *Temp = nullptr;
      Head = cutList(&Head, &Temp,
                     SplittedSize + (Ret.size() < NumOfListWithOneMoreElement));
      Ret.push_back(Temp);
    }
    return Ret;
  }

private:
  int getListSize(ListNode *Head) {
    int Ret = 0;
    while (Head) {
      Head = Head->next;
      Ret++;
    }
    return Ret;
  }

  // Refer to 148.
  ListNode *cutList(ListNode **Head, ListNode **Dest, int Size) {
    *Dest = *Head;
    while (Size-- && *Head != nullptr) {
      Head = &(*Head)->next;
    }
    auto RemainingHead = *Head;
    *Head = nullptr;
    return RemainingHead;
  }
};