#include "headers.hpp"

class Solution {
  constexpr static int Mod_ = 1000000007;

public:
  // Note that, by assumption, node value is positive.
  int maxProduct(TreeNode *Root) {
    auto RootSum = sum_(Root);
    // Precisely, we should start the recursion from Root->left and Root->right.
    // But starting from Root is OK, since the calculated product from Root is
    // zero.
    calProductAndReturnSumOfNode_(Root, RootSum);
    return MaxProduct_ % Mod_;
  }

private:
  int64_t MaxProduct_ = 0;

  int sum_(TreeNode *Root) {
    if (!Root) {
      return 0;
    }
    return Root->val + sum_(Root->left) + sum_(Root->right);
  }

  // Return the sum of node values of the tree rooted at Root.
  // And calculate the maximum product where the "splitting point" is the given
  // Root.
  int calProductAndReturnSumOfNode_(TreeNode *Root, int RootSum) {
    if (!Root) {
      return 0;
    }

    auto Sum = Root->val + calProductAndReturnSumOfNode_(Root->left, RootSum) +
               calProductAndReturnSumOfNode_(Root->right, RootSum);
    MaxProduct_ = std::max(MaxProduct_, (int64_t)Sum * (RootSum - Sum));
    return Sum;
  }
};
