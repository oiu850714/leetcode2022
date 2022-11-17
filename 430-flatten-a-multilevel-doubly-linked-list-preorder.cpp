#include "headers.hpp"

// Definition for a Node.
class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

// Treat the multilevel list as "binary tree", with child as left and next as
// right children.
class Solution {
public:
  Node *flatten(Node *Head) {
    preorder(Head);
    return Head;
  }

private:
  Node *preorder(Node *Root) {
    if (Root == nullptr) {
      return Root;
    } else if (Root->next == nullptr && Root->child == nullptr) {
      // Return last valid node.
      return Root;
    } else if (Root->child == nullptr && Root->next != nullptr) {
      // Root has next but has no child.
      return preorder(Root->next);
    } else if (Root->child != nullptr && Root->next == nullptr) {
      // Root has no next but has child.
      Root->next = Root->child;
      Root->child = nullptr;
      Root->next->prev = Root;
      return preorder(Root->next);
    } else {
      // Now Root has both next and child.
      auto OldChild = Root->child;
      Root->child = nullptr;
      auto OldNext = Root->next;

      Root->next = OldChild;
      Root->next->prev = Root;
      auto OldChildFlattenLastNode = preorder(OldChild);
      OldChildFlattenLastNode->next = OldNext;
      OldNext->prev = OldChildFlattenLastNode;
      return preorder(OldNext);
    }
  }
};
