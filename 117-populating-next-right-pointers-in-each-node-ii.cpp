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
  void connectRecursive_(Node *Curr) {
    if (!Curr) {
      return;
    }

    // Curr is leaf node.
    if (!Curr->left && !Curr->right) {
      return;
    }

    // Else, Curr has at least one child.

    auto NonSiblingNext = pickNonSiblingNextOfChild_(Curr);

    if (Curr->left && !Curr->right) {
      Curr->left->next = NonSiblingNext;
    } else if (!Curr->left && Curr->right) {
      Curr->right->next = NonSiblingNext;
    } else {
      Curr->left->next = Curr->right;
      Curr->right->next = NonSiblingNext;
    }

    // Note that this right-first-then-left call order of IS essential.
    // The order guaranteed that all the possible next links we may traverse in
    // the pickNonSiblingNextOfChild_ function call have beed constructed.
    connectRecursive_(Curr->right);
    connectRecursive_(Curr->left);
  }

  Node *pickNonSiblingNextOfChild_(Node *Curr) {
    while (Curr->next) {
      if (Curr->next->left) {
        return Curr->next->left;
      }
      if (Curr->next->right) {
        return Curr->next->right;
      }
      Curr = Curr->next;
    }
    return nullptr;
  }
};
