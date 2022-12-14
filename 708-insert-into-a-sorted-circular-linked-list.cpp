#include "headers.hpp"

using Node = ListNode;

class Solution {
public:
  Node *insert(Node *Head, int InsertVal) {
    auto NewNode = new Node(InsertVal);
    // Empty list.
    if (!Head) {
      NewNode->next = NewNode;
      return NewNode;
    }

    // Singleton list.
    if (Head->next == Head) {
      Head->next = NewNode;
      NewNode->next = Head;
      return Head;
    }

    // Now the list has at least two nodes.
    auto [Prev, Smallest] = getPrevOfSmallestAndSmallest_(Head);
    auto Curr = Smallest;
    while (Curr->val < InsertVal) {
      Curr = Curr->next;
      Prev = Prev->next;
      if (Curr == Smallest) {
        // We have visited all nodes.
        break;
      }
    }
    NewNode->next = Curr;
    Prev->next = NewNode;
    return Head;
  }

private:
  // Assume the circular list has at least two nodes.
  std::pair<Node *, Node *> getPrevOfSmallestAndSmallest_(Node *Head) {
    auto Ret = Head;
    auto MinVal = Head->val;
    auto Curr = Ret->next;
    while (Curr != Head) {
      if (Curr->val < MinVal) {
        MinVal = Curr->val;
        Ret = Curr;
      }
      Curr = Curr->next;
    }
    auto Prev = Ret;
    while (Prev->next != Ret) {
      Prev = Prev->next;
    }
    return {Prev, Ret};
  }
};
