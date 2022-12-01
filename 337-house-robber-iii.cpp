#include "headers.hpp"

class Solution {
public:
  int rob(TreeNode *Root) {
    auto [CostWithRoot, CostWithoutRoot] = robRecursive_(Root);
    return std::max(CostWithRoot, CostWithoutRoot);
  }

  // <MaxCost including Root, MaxCost excluding Root>
  // The structure is somewhat similar to 1372.
  std::pair<int, int> robRecursive_(TreeNode *Root) {
    if (!Root) {
      return {0, 0};
    }
    auto [LWithRoot, LWithoutRoot] = robRecursive_(Root->left);
    auto [RWithRoot, RWithoutRoot] = robRecursive_(Root->right);

    // If we choose Root, we cannot choose any child.
    auto CostWithRoot = Root->val + LWithoutRoot + RWithoutRoot;
    // If we do not choose Root, then we choose the best possible subpaths.
    auto CostWithouRoot =
        std::max(LWithRoot, LWithoutRoot) + std::max(RWithRoot, RWithoutRoot);
    return {CostWithRoot, CostWithouRoot};
  }
};
