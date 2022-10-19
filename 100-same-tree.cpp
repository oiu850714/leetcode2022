#include "headers.hpp"

class Solution {
public:
  // Related problem: 101.
  bool isSameTree(TreeNode *T1, TreeNode *T2) {
    if (!T1 && !T2) {
      // Empty trees are vacuously the same.
      return true;
    }

    if (!T1 || !T2) {
      // Only one of them is empty.
      return false;
    }

    // The root values of each tree are different.
    if (T1->val != T2->val) {
      return false;
    }

    // Recursively compare the T1->left and T2->left, T1->right and T2->right,
    // respectively.
    return (isSameTree(T1->left, T2->left) && isSameTree(T1->right, T2->right));
  }
};