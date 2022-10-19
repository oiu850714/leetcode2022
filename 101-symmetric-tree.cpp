#include "headers.hpp"

class Solution {
  // A tree is symmetric iff it's the mirror reflection of itself.
public:
  bool isSymmetric(const TreeNode *Root) {
    return isMirrorReflection(Root, Root);
  }

  // And two trees T1, T2 are mirror reflections of each other if
  // 1. Their roots have the same value.
  // 2. T1's left subtree is the mirror reflection of T2's right subtree, and
  // 3. T1's right subtree is the mirror reflection of T2's left subtree.
  bool isMirrorReflection(const TreeNode *Root1, const TreeNode *Root2) {
    if (!Root1 && !Root2) {
      // Empty trees are vacuously reflection to each other.
      return true;
    }

    if (!Root1 || !Root2) {
      // One tree is empty but the other is not.
      return false;
    }

    if (Root1->val != Root2->val) {
      // The root value of both tree are different.
      return false;
    }

    return isMirrorReflection(Root1->left, Root2->right) &&
           isMirrorReflection(Root1->right, Root2->left);
  }
};