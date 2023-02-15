#include "headers.hpp"

class Solution {
public:
  TreeNode *removeLeafNodes(TreeNode *Root, int Target) {
    // Note that, not sure but, it seems leetcode will still access the nodes
    // allocted before this call. So I do not delete the to-be-removed nodes.
    if (isAProcessedTargetLeaf(Root, Target)) {
      return nullptr;
    } else {
      return Root;
    }
  }

  bool isAProcessedTargetLeaf(TreeNode *Root, int Target) {
    if (!Root) {
      return false;
    }
    if (isAProcessedTargetLeaf(Root->left, Target)) {
      Root->left = nullptr;
    }
    if (isAProcessedTargetLeaf(Root->right, Target)) {
      Root->right = nullptr;
    }

    return !Root->left && !Root->right && Root->val == Target;
  }
};
