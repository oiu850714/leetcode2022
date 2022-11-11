#include "headers.hpp"

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *Head) {
    // [DupStart, DupEnd).
    auto DupStart = &Head, DupEnd = &Head;
    int Counter = 0;
    while (*DupEnd) {
      if ((*DupEnd)->val == (*DupStart)->val) {
        Counter++;
        DupEnd = &(*DupEnd)->next;
      } else {
        if (Counter >= 2) {
          std::tie(DupStart, DupEnd) =
              removeDupAndReturnNewBound_(DupStart, DupEnd);
        } else {
          DupStart = DupEnd;
        }
        Counter = 0;
      }
    }
    // Duplicates at the end.
    if (Counter >= 2) {
      removeDupAndReturnNewBound_(DupStart, DupEnd);
    }
    return Head;
  }

private:
  std::pair<ListNode **, ListNode **>
  removeDupAndReturnNewBound_(ListNode **DupStart, ListNode **DupEnd) {
    auto RemoveStart = *DupStart, RemoveEnd = *DupEnd;
    *DupStart = *DupEnd;
    DupEnd = DupStart;
    removeNodes_(RemoveStart, RemoveEnd);
    return {DupStart, DupEnd};
  }

  // Assume Head != nullptr.
  void removeNodes_(ListNode *Head, ListNode *End) {
    while (Head != End) {
      auto NewHead = Head->next;
      delete Head;
      Head = NewHead;
    }
  }
};
