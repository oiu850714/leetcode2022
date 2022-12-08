#include "headers.hpp"

class Solution {
public:
  void deleteNode(ListNode *Node) {
    assert(Node && Node->next);
    std::swap(Node->val, Node->next->val); // Swap node details.
    auto ToBeDeleted = Node->next;
    Node->next = Node->next->next;
    delete ToBeDeleted;
  }
};
