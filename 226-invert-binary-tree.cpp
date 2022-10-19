#include "headers.hpp"

class Solution {
public:
  TreeNode *invertTree(TreeNode *Root) {
    if (!Root) {
      return Root;
    }
    invertTree(Root->left);
    invertTree(Root->right);
    std::swap(Root->left, Root->right);
    return Root;
  }
};