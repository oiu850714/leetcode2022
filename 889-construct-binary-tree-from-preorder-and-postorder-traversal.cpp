#include "headers.hpp"

class Solution {
public:
  TreeNode *constructFromPrePost(std::vector<int> &Preorder,
                                 std::vector<int> &Postorder) {
    for (int i = 0; i < Postorder.size(); i++) {
      PostorderValIdxMap_[Postorder[i]] = i;
    }

    Preorder_ = std::move(Preorder);
    Postorder_ = std::move(Postorder);

    int PreBeg = 0, PostBeg = 0, TreeSize = Preorder_.size();
    // IMPORTANT: the corresponding intervals in pre- and post-order traversal
    // of the subtrees may not have the same starting index, so we need to pass
    // the starting indices of the two intervals, respectively.
    return buildFullBinaryTree_(PreBeg, PostBeg, TreeSize);
  }

private:
  std::vector<int> Postorder_;
  std::vector<int> Preorder_;
  std::unordered_map<int, int> PostorderValIdxMap_;

  TreeNode *buildFullBinaryTree_(int PreBeg, int PostBeg, int TreeSize) {
    if (TreeSize == 0) {
      return nullptr;
    }

    auto RootVal = Preorder_[PreBeg];
    auto Root = new TreeNode(RootVal);

    if (TreeSize <= 1) {
      return Root;
    }

    // Now you can see the different offsets of these four begin indices:
    // LTreePreBeg,
    // LTreePostBeg,
    // RTreePreBeg,
    // RTreePostBeg.
    auto LTreePreBeg = PreBeg + 1;
    auto LTreePostBeg = PostBeg;

    // We can use the "position of the root value of left subtree" in the
    // post-order traversal to calculate the left subtree size.
    auto LTreeSize =
        PostorderValIdxMap_.at(Preorder_[LTreePreBeg]) - PostBeg + 1;

    auto RTreePreBeg = PreBeg + 1 + LTreeSize;
    auto RTreePostBeg = PostBeg + LTreeSize;
    auto RTreeSize = TreeSize - LTreeSize - 1;
    Root->left = buildFullBinaryTree_(LTreePreBeg, LTreePostBeg, LTreeSize);
    Root->right = buildFullBinaryTree_(RTreePreBeg, RTreePostBeg, RTreeSize);

    return Root;
  }
};
