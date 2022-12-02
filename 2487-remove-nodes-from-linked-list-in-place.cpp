#include "headers.hpp"

class Solution {
public:
  ListNode *removeNodes(ListNode *Head) {
    // NodesWithoutNGE is actually a monotonic stack.
    std::vector<ListNode *> NodesWithoutNGE;
    {
      auto Curr = Head;
      while (Curr) {
        while (!NodesWithoutNGE.empty() &&
               NodesWithoutNGE.back()->val < Curr->val) {
          NodesWithoutNGE.pop_back();
        }
        NodesWithoutNGE.push_back(Curr);
        Curr = Curr->next;
      }
    }

    // Now all the nodes in the "stack" have no next greater node.
    // And the relative order of nodes in the stack(actually, vector) is the
    // same as the order in the original list.

    auto Curr = &Head;
    int Idx = 0;
    while (*Curr) {
      if (*Curr == NodesWithoutNGE[Idx]) {
        Curr = &(*Curr)->next;
        Idx++;
      } else {
        auto NodeToBeDeleted = *Curr;
        *Curr = (*Curr)->next;
        delete NodeToBeDeleted;
      }
    }

    return Head;
  }
};
