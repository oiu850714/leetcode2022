#include "headers.hpp"
// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = NULL;
    right = NULL;
  }

  Node(int _val, Node *_left, Node *_right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

class Solution {
public:
  Node *treeToDoublyList(Node *Root) {
    inorderTraversal_(Root);
    if (Head != nullptr) {
      Head->left = Last;
      Last->right = Head;
    }
    return Head;
  }

private:
  Node *Head = nullptr;
  Node *Last = nullptr;

  void inorderTraversal_(Node *Root) {
    if (!Root) {
      return;
    }
    inorderTraversal_(Root->left);
    if (Last == nullptr) {
      Head = Last = Root;
    } else {
      Root->left = Last;
      Last->right = Root;
      Last = Root;
    }
    inorderTraversal_(Root->right);
  }
};
