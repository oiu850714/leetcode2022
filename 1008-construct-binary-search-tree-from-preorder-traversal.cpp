#include "headers.hpp"

class Solution {
public:
  TreeNode *bstFromPreorder(std::vector<int> &Preorder) {
    return buildBST_(Preorder, Preorder.cbegin(), Preorder.size());
  }

private:
  TreeNode *buildBST_(std::vector<int> &Preorder,
                      std::vector<int>::const_iterator Beg, int Size) {
    if (Size == 0) {
      return nullptr;
    }

    auto RootVal = *Beg;
    auto Root = new TreeNode(RootVal);

    if (Size == 1) {
      return Root;
    }

    auto RTreeBeg = std::find_if(Beg, Beg + Size,
                                 [RootVal](auto Val) { return Val > RootVal; });
    auto RTreeSize = Size - (RTreeBeg - Beg);
    auto LTreeSize = Size - RTreeSize - 1;
    auto LTreeBeg = Beg + 1;
    Root->left = buildBST_(Preorder, LTreeBeg, LTreeSize);
    Root->right = buildBST_(Preorder, RTreeBeg, RTreeSize);
    return Root;
  }
};
