#include "headers.hpp"

class Solution {
public:
  void flatten(TreeNode *Root) { flattenRecursive_(&Root); }

private:
  // Return the DOUBLE POINTER of the tail(precisely, the pointer of "right" of
  // the last tree node) of the flatterned tree.
  TreeNode **flattenRecursive_(TreeNode **Root) {
    // Tree is empty.
    if (*Root == nullptr) {
      return Root;
    }

    auto OldRightSubtree = (*Root)->right;
    (*Root)->right = (*Root)->left;
    (*Root)->left = nullptr;

    auto FlattenedLeftSubtreeTail = flattenRecursive_(&(*Root)->right);
    (*FlattenedLeftSubtreeTail) = OldRightSubtree;
    return flattenRecursive_(FlattenedLeftSubtreeTail);
  }
};
