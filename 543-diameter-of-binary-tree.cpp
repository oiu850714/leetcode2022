#include "headers.hpp"

class Solution {
public:
  int diameterOfBinaryTree(TreeNode *Root) {
    return treeHeightAndDiameter(Root).second;
  }

private:
  std::pair<int, int> treeHeightAndDiameter(TreeNode *Root) {
    if (!Root) {
      // The convention is that empty tree has height -1.
      // And that makes calculating the height non-empty recursively more
      // convient.
      return {-1, 0};
    }
    auto [LeftTreeHeight, LeftDiameter] = treeHeightAndDiameter(Root->left);
    auto [RightTreeHeight, RightDiameter] = treeHeightAndDiameter(Root->right);

    auto TreeHeight = std::max(LeftTreeHeight, RightTreeHeight) + 1;
    auto DiameterPassingRoot = 0;
    if (Root->left) {
      DiameterPassingRoot += 1 + LeftTreeHeight;
    }
    if (Root->right) {
      DiameterPassingRoot += 1 + RightTreeHeight;
    }
    auto Diameter =
        std::max({LeftDiameter, RightDiameter, DiameterPassingRoot});
    return {TreeHeight, Diameter};
  }
};