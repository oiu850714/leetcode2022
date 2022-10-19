#include "headers.hpp"

class Solution {
public:
  bool isBalanced(TreeNode *Root) try {
    checkTreeHeightBalenced(Root);
    return true;
  } catch (const std::exception &E) {
    return false;
  }

private:
  int checkTreeHeightBalenced(TreeNode *Root) {
    if (!Root) {
      // Empty tree is vacuously balenced by definition.
      return 0;
    }
    auto LeftHeight = checkTreeHeightBalenced(Root->left);
    auto RightHeight = checkTreeHeightBalenced(Root->right);
    if (std::abs(LeftHeight - RightHeight) > 1) {
      throw std::runtime_error("Tree unbalanced");
    }
    return std::max(LeftHeight, RightHeight) + 1;
  }
};