#include "headers.hpp"

class BSTIterator {
public:
  BSTIterator(TreeNode *Root) { pushUntilLeftmostChild(Root); }

  int next() {
    auto Node = Stack_.top();
    Stack_.pop();
    auto Ret = Node->val;
    auto RightSubTree = Node->right;
    pushUntilLeftmostChild(RightSubTree);
    return Ret;
  }

  bool hasNext() { return !Stack_.empty(); }

private:
  std::stack<TreeNode *> Stack_;

  void pushUntilLeftmostChild(TreeNode *Node) {
    while (Node) {
      Stack_.push(Node);
      Node = Node->left;
    }
  }
};