#include "headers.hpp"

class Solution {
public:
  bool hasPathSum(TreeNode *Root, int TargetSum) {
    if (!Root) {
      // empty tree by definition "does not have" a non-empty root-to-leaf path.
      return false;
    }

    if (!Root->left && !Root->right) {
      return TargetSum == Root->val;
    }

    int SubTargetSum = TargetSum - Root->val;
    return (hasPathSum(Root->left, SubTargetSum)) ||
           (hasPathSum(Root->right, SubTargetSum));
  }
};