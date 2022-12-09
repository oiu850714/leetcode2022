#include "headers.hpp"

class Solution {
public:
  int maxAncestorDiff(TreeNode *Root) {
    backtrack_(Root);
    return Result_;
  }

private:
  int Result_ = 0;
  // Return <Min, Max> of the whole tree.
  std::pair<int, int> backtrack_(TreeNode *Root) {
    constexpr auto IntMax = std::numeric_limits<int>::max(),
                   IntMin = std::numeric_limits<int>::min();
    if (!Root) {
      return {IntMax, IntMin};
    }

    auto [LeftMin, LeftMax] = backtrack_(Root->left);
    auto [RightMin, RightMax] = backtrack_(Root->right);
    auto BothMin = std::min(LeftMin, RightMin);
    auto BothMax = std::max(LeftMax, RightMax);
    if (BothMin != IntMax) {
      Result_ = std::max(Result_, std::abs(Root->val - BothMin));
    }
    if (BothMax != IntMin) {
      Result_ = std::max(Result_, std::abs(Root->val - BothMax));
    }

    return {std::min(BothMin, Root->val), std::max(BothMax, Root->val)};
  }
};
