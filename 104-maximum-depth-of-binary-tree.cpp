#include "headers.hpp"

class Solution {
public:
  int maxDepth(TreeNode *Root) {
    if (!Root) {
      return 0;
    }
    auto LeftTreeDepth = maxDepth(Root->left);
    auto RightTreeDepth = maxDepth(Root->right);
    return std::max(LeftTreeDepth, RightTreeDepth) + 1;
  }
};