#include "headers.hpp"

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *Root) {
    connectRecursive_(Root);
    return Root;
  }

private:
  void connectRecursive_(Node *Root) {
    if (!Root) {
      return;
    }

    if (!Root->left && !Root->right) {
      // Leaf node.
      return;
    }

    // Else, Root has both children, since the tree is perfectly binary.
    // Connect left to right, and connect right to the nonsibling-next, using
    // Root's next.
    Root->left->next = Root->right;
    if (Root->next) {
      Root->right->next = Root->next->left;
    }

    connectRecursive_(Root->left);
    connectRecursive_(Root->right);
  }
};
