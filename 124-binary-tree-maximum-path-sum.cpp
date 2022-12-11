#include "headers.hpp"

class Solution {
public:
  int maxPathSum(TreeNode *Root) {
    dfs_(Root);
    return Result_;
  }

private:
  int Result_ = std::numeric_limits<int>::min();

  // 1. Calculate the max sequence sum, where the sequence MUST pass Root.
  // 2. Return the max path sum that (also) starts from Root.
  // Since dfs_ is called on each node, we calculate all possible sequences.
  int dfs_(TreeNode *Root) {
    if (!Root) {
      return 0;
    }

    auto LeftMaxRootPathSum = std::max(dfs_(Root->left), 0);
    auto RightMaxRootPathSum = std::max(dfs_(Root->right), 0);
    Result_ =
        std::max(Result_, LeftMaxRootPathSum + RightMaxRootPathSum + Root->val);

    return Root->val + std::max(LeftMaxRootPathSum, RightMaxRootPathSum);
  }
};
