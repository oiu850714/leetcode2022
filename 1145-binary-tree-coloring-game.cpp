#include "headers.hpp"

class Solution {
public:
  bool btreeGameWinningMove(TreeNode *Root, int N, int X) {
    auto NodeX = findX(Root, X);
    assert(NodeX);
    auto LeftCount = countNodes(NodeX->left);
    auto RightCount = countNodes(NodeX->right);
    auto ParentCount = N - 1 - LeftCount - RightCount;
    auto Half = (N - 1) >> 1;
    return LeftCount > Half || RightCount > Half || ParentCount > Half;
  }

private:
  int countNodes(TreeNode *Root) {
    return !Root ? 0 : 1 + countNodes(Root->left) + countNodes(Root->right);
  }

  TreeNode *findX(TreeNode *Root, int X) {
    if (!Root) {
      return nullptr;
    }

    if (Root->val == X) {
      return Root;
    }

    auto LeftResult = findX(Root->left, X);
    if (LeftResult && LeftResult->val == X) {
      return LeftResult;
    }

    auto RightResult = findX(Root->right, X);
    if (RightResult && RightResult->val == X) {
      return RightResult;
    }

    return nullptr;
  }
};
