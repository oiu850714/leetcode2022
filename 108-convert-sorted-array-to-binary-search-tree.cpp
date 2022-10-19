#include "headers.hpp"

class Solution {
public:
  TreeNode *sortedArrayToBST(const std::vector<int> &Nums) {
    return constructBSTRecursive(Nums, 0, Nums.size());
  }

private:
  TreeNode *constructBSTRecursive(const std::vector<int> &Nums, int Beg,
                                  int End) {
    if (Beg == End) {
      return nullptr;
    }
    auto Node = new TreeNode;
    auto Mid = Beg + (End - Beg) / 2;
    Node->val = Nums[Mid];
    Node->left = constructBSTRecursive(Nums, Beg, Mid);
    Node->right = constructBSTRecursive(Nums, Mid + 1, End);
    return Node;
  }
};