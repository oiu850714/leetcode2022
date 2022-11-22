#include "headers.hpp"

class Solution {
public:
  TreeNode *buildTree(std::vector<int> Preorder, std::vector<int> Inorder) {
    for (int i = 0; i < Inorder.size(); i++) {
      InorderValIdxMap_[Inorder[i]] = i;
    }

    Preorder_ = std::move(Preorder);
    Inorder_ = std::move(Inorder);

    int TreeBeg = 0, TreeEnd = Inorder_.size(), RootPreordIdx = 0;
    return buildTreeRecursive_(RootPreordIdx, TreeBeg, TreeEnd);
  }

private:
  std::vector<int> Inorder_;
  std::vector<int> Preorder_;
  std::unordered_map<int, int> InorderValIdxMap_;
  // [TreeBeg, TreeEnd)
  TreeNode *buildTreeRecursive_(int RootPreordIdx, int TreeBeg, int TreeEnd) {
    if (TreeBeg == TreeEnd) {
      return nullptr;
    }

    auto RootVal = Preorder_[RootPreordIdx];
    auto Root = new TreeNode(RootVal);
    auto RootInordIdx = InorderValIdxMap_.at(RootVal);
    auto LTreeSize = RootInordIdx - TreeBeg;
    auto LTreeRootPreordIdx = RootPreordIdx + 1;
    auto RTreeRootPreordIdx = RootPreordIdx + 1 + LTreeSize;
    Root->left = buildTreeRecursive_(LTreeRootPreordIdx, TreeBeg, RootInordIdx);
    Root->right =
        buildTreeRecursive_(RTreeRootPreordIdx, RootInordIdx + 1, TreeEnd);
    return Root;
  }
};
