#include "headers.hpp"

class Solution {
public:
  int minDepth(TreeNode *Root) {
    // Notice the definition of minimum depth!!
    if (!Root) {
      return 0;
    }
    if (!Root->left) {
      return minDepth(Root->right) + 1;
    }
    if (!Root->right) {
      return minDepth(Root->left) + 1;
    }
    return std::min(minDepth(Root->left), minDepth(Root->right)) + 1;
  }
};