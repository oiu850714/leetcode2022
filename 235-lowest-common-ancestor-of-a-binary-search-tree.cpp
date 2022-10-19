#include "headers.hpp"

class Solution {
public:
  // Assume all the constraints are true.
  TreeNode *lowestCommonAncestor(TreeNode *Root, TreeNode *P, TreeNode *Q) {
    while (true) {
      // Both P, Q are in the left subtree.
      if (Root->val > P->val && Root->val > Q->val) {
        Root = Root->left;
        // Both P, Q are in the right subtree.
      } else if (Root->val < P->val && Root->val < Q->val) {
        Root = Root->right;
        // All other cases in which the Root is the LCA:
        //   1. P, Q are in the left and right subtrees, respectively(or vise
        //   versa)
        //   2. One of P or Q is actually equal to the Root.
      } else {
        return Root;
      }
    }
  }
};