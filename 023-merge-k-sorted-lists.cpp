#include "headers.hpp"

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &Lists) {
    if (Lists.empty()) {
      // Base case: no lists at all.
      return nullptr;
    }
    while (Lists.size() > 1) {
      std::vector<ListNode *> MergesLists;
      for (int i = 0; i < Lists.size(); i += 2) {
        if (i + 1 == Lists.size()) {
          MergesLists.push_back(Lists[i]);
        } else {
          MergesLists.push_back(mergeTwoLists(Lists[i], Lists[i + 1]));
        }
      }
      Lists = std::move(MergesLists);
    }
    return Lists[0];
  }

  // Copied from 021.
  ListNode *mergeTwoLists(ListNode *List1, ListNode *List2) {
    ListNode *Ret = nullptr;
    auto Curr = &Ret;
    while (List1 != nullptr && List2 != nullptr) {
      if (List1->val <= List2->val) {
        *Curr = List1;
        Curr = &List1->next;
        List1 = List1->next;
      } else {
        *Curr = List2;
        Curr = &List2->next;
        List2 = List2->next;
      }
    }

    // Concate remaining nodes
    *Curr = List1 != nullptr ? List1 : List2;

    return Ret;
  }
};