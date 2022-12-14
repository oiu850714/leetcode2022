#include "headers.hpp"

class Solution {
public:
  TreeNode *upsideDownBinaryTree(TreeNode *Root) {
    return upsideDownBinaryTreeRecurvie_(Root).first;
  }

  // Return <NewRoot, Rightmost child of NewRoot>
  std::pair<TreeNode *, TreeNode *>
  upsideDownBinaryTreeRecurvie_(TreeNode *OldRoot) {
    if (!OldRoot) {
      return {nullptr, nullptr};
    }

    if (!OldRoot->left) {
      // Then by the assumption, OldRoot has no right child.
      // The assumption is an if-else statement: if OldRoot has right child,
      // then it has left child. So the contrapositive is: if OldRoot has no
      // left child, then it has no right child.
      return {OldRoot, OldRoot};
    } else {
      auto [NewRoot, NewRootRightmost] =
          upsideDownBinaryTreeRecurvie_(OldRoot->left);
      // Note that we actually do not care whether there is an (old) right
      // child.
      // And when OldRoot != nullptr, NewRootRightmost ALWAYS != nullptr.
      // (It may be OldRoot itself; see the return value of the if-branch).
      auto OldRight = OldRoot->right;
      OldRoot->left = nullptr;
      OldRoot->right = nullptr;
      NewRootRightmost->left = OldRight;
      NewRootRightmost->right = OldRoot;
      return {NewRoot, OldRoot};
    }
  }
};
