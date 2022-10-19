#include "headers.hpp"

class Solution {
public:
  bool isValidBST(TreeNode *Root) try {
    traverse(Root);
    return true;
  } catch (std::exception &) {
    return false;
  }

private:
  void traverse(TreeNode *Root) {
    if (!Root) {
      return;
    }
    traverse(Root->left);
    if (HasSetCurrentVal && Root->val <= CurrentVal_) {
      throw std::runtime_error("Not a valid BST");
    }
    if (!HasSetCurrentVal) {
      HasSetCurrentVal = true;
    }
    CurrentVal_ = Root->val;
    traverse(Root->right);
    return;
  }
  bool HasSetCurrentVal = false;
  int CurrentVal_ = 0;
};