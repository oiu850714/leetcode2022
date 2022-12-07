#include "headers.hpp"

class Solution {
public:
  int rangeSumBST(TreeNode *Root, int Low, int High) {
    Low_ = Low, High_ = High;
    backtrack_(Root);
    return Result_;
  }

private:
  int Result_ = 0;
  int Low_ = 0;
  int High_ = 0;

  void backtrack_(TreeNode *Root) {
    if (!Root) {
      return;
    }

    if (Root->val >= Low_ && Root->val <= High_) {
      // Root->val is in the range.
      Result_ += Root->val;
      // The subtrees may also have valid values.
      backtrack_(Root->left);
      backtrack_(Root->right);
    } else if (Root->val < Low_) {
      // Then we can skip left subtree since all nodes in left subtree have val
      // < Root->val.
      backtrack_(Root->right);
    } else if (Root->val > High_) {
      // Then we can skip right subtree since all nodes in right subtree have
      // val > Root->val.
      backtrack_(Root->left);
    }
  }
};
