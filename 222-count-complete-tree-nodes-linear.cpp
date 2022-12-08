#include "headers.hpp"

class Solution {
public:
  int countNodes(TreeNode *Root) {
    if (!Root) {
      return 0;
    }
    return countNodes(Root->left) + countNodes(Root->right) + 1;
  }
};