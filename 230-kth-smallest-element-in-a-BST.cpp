#include "headers.hpp"

class Solution {
public:
  int kthSmallest(TreeNode *Root, int K) {
    K_ = K;
    Counter_ = 0;
    kthSmallestRecursive(Root);
    return Result_;
  }

private:
  int K_;
  int Counter_;
  int Result_;
  // If returning false, then we have found the K-th value.
  bool kthSmallestRecursive(TreeNode *Node) {
    if (!Node) {
      return true;
    }
    if (!kthSmallestRecursive(Node->left)) {
      return false;
    }
    if (++Counter_ == K_) {
      Result_ = Node->val;
      return false;
    }
    return kthSmallestRecursive(Node->right);
  }
};