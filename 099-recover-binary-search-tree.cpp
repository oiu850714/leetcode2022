#include "headers.hpp"

class Solution {
public:
  void recoverTree(TreeNode *Root) {
    // Glitch means the pair in the inorder traversal that we first see a larger
    // node then a smaller one.
    inorderToFindGlitch_(Root);
    std::swap(First_->val, Second_->val);
  }

private:
  bool HasSetPrev_ = false;
  TreeNode *Prev_ = nullptr;
  int NumEncounteredGlitches_ = 0;
  TreeNode *First_ = nullptr;
  TreeNode *Second_ = nullptr;
  void inorderToFindGlitch_(TreeNode *Root) {
    if (!Root) {
      return;
    }
    inorderToFindGlitch_(Root->left);
    if (!HasSetPrev_) {
      HasSetPrev_ = true;
      Prev_ = Root;
    } else {
      if (Prev_->val > Root->val) {
        // There may be one or two glitch points in which the two branches below
        // correspond to.
        if (NumEncounteredGlitches_ == 0) {
          First_ = Prev_;
          Second_ = Root;
          NumEncounteredGlitches_++;
        } else {
          Second_ = Root;
        }
      }
      Prev_ = Root;
    }
    inorderToFindGlitch_(Root->right);
  }
};
