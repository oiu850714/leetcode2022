#include "headers.hpp"

class Solution {
  constexpr static int Mod_ = 1000000007;

  using ProductsTy = std::unordered_map<TreeNode *, int>;

public:
  // Note that, by assumption, node value is positive.
  int maxProduct(TreeNode *Root) {
    const auto AllNodeSums = calculateSums_(Root);
    RootSum_ = AllNodeSums.at(Root);
    calculateSplittedSumOfProduct_(AllNodeSums, Root);
    // Also note that we can just % the result in the end, since the sum of each
    // tree <= 50k * 10k.
    // The possible maximum product is thus (50k * 10k)^2, which fits in
    // int64_t.
    return Result_ % Mod_;
  }

private:
  int64_t Result_ = 0;
  // By the test cases, the root sum is at most 50k * 10k <= INT_MAX.
  int RootSum_;
  ProductsTy calculateSums_(TreeNode *Root) {
    ProductsTy Ret;
    calculate_(Ret, Root);
    return Ret;
  }

  // Assume Root never be nullptr.
  void calculate_(ProductsTy &Products, TreeNode *Root) {
    int Sum = Root->val;
    if (Root->left) {
      calculate_(Products, Root->left);
      Sum += Products[Root->left];
    }

    if (Root->right) {
      calculate_(Products, Root->right);
      Sum += Products[Root->right];
    }

    Products[Root] = Sum;
    return;
  }

  void calculateSplittedSumOfProduct_(const ProductsTy &Products,
                                      TreeNode *Root) {
    if (!Root || (!Root->left && !Root->right)) {
      return;
    }

    // SOP: Sum Of Product.
    int64_t CutLeftEdgeSOP = 0;
    if (Root->left) {
      auto LeftSum = Products.at(Root->left);
      CutLeftEdgeSOP = (int64_t)LeftSum * (RootSum_ - LeftSum);
    }
    int64_t CutRightEdgeSOP = 0;
    if (Root->right) {
      auto RightSum = Products.at(Root->right);
      CutRightEdgeSOP = (int64_t)RightSum * (RootSum_ - RightSum);
    }
    Result_ = std::max(Result_, std::max(CutLeftEdgeSOP, CutRightEdgeSOP));

    calculateSplittedSumOfProduct_(Products, Root->left);
    calculateSplittedSumOfProduct_(Products, Root->right);
  }
};
