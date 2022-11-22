#include "headers.hpp"

class Solution {
public:
  TreeNode *buildTree(std::vector<int> Inorder, std::vector<int> Postorder) {
    for (int i = 0; i < Inorder.size(); i++) {
      InorderValIdxMap_[Inorder[i]] = i;
    }

    Inorder_ = std::move(Inorder);
    Postorder_ = std::move(Postorder);

    int TreeBeg = 0, TreeEnd = Inorder_.size(),
        RootPostordIdx = Postorder_.size() - 1;
    return buildTreeRecursive_(RootPostordIdx, TreeBeg, TreeEnd);
  }

private:
  std::vector<int> Inorder_;
  std::vector<int> Postorder_;
  std::unordered_map<int, int> InorderValIdxMap_;
  // [TreeBeg, TreeEnd)
  TreeNode *buildTreeRecursive_(int RootPostordIdx, int TreeBeg, int TreeEnd) {
    if (TreeBeg == TreeEnd) {
      return nullptr;
    }

    auto RootVal = Postorder_[RootPostordIdx];
    auto Root = new TreeNode(RootVal);
    auto RootInordIdx = InorderValIdxMap_.at(RootVal);

    // Think carefully about the "- 1" in the initializer.
    auto RTreeSize = TreeEnd - RootInordIdx - 1;

    auto LTreeRootPostordIdx = RootPostordIdx - 1 - RTreeSize;
    auto RTreeRootPostordIdx = RootPostordIdx - 1;
    Root->left =
        buildTreeRecursive_(LTreeRootPostordIdx, TreeBeg, RootInordIdx);
    Root->right =
        buildTreeRecursive_(RTreeRootPostordIdx, RootInordIdx + 1, TreeEnd);
    return Root;
  }
};
