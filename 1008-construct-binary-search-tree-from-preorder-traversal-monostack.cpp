#include "headers.hpp"

class Solution {
public:
  TreeNode *bstFromPreorder(std::vector<int> &Preorder) {
    NextGreater_ = constructNextGreater_(Preorder);
    return buildBST_(Preorder, 0, Preorder.size());
  }

private:
  std::vector<int> NextGreater_;
  std::vector<int> constructNextGreater_(const std::vector<int> &Preorder) {
    std::vector<int> Ret(Preorder.size(), Preorder.size());
    std::stack<int> MonoStack;
    for (int i = 0; i < Preorder.size(); i++) {
      while (!MonoStack.empty() && Preorder[MonoStack.top()] < Preorder[i]) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }
  TreeNode *buildBST_(std::vector<int> &Preorder, int Beg, int Size) {
    if (Size == 0) {
      return nullptr;
    }

    auto RootVal = Preorder[Beg];
    auto Root = new TreeNode(RootVal);

    if (Size == 1) {
      return Root;
    }

    // O(1) to find right subtree root.
    auto RTreeBeg = NextGreater_[Beg];
    auto RTreeSize = Size - (RTreeBeg - Beg);
    auto LTreeSize = Size - RTreeSize - 1;
    auto LTreeBeg = Beg + 1;
    Root->left = buildBST_(Preorder, LTreeBeg, LTreeSize);
    Root->right = buildBST_(Preorder, RTreeBeg, RTreeSize);
    return Root;
  }
};
