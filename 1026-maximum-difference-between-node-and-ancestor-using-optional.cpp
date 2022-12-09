#include "headers.hpp"
#include <optional>

class Solution {
public:
  int maxAncestorDiff(TreeNode *Root) {
    backtrack_(Root);
    return Result_;
  }

private:
  int Result_ = 0;
  // Return <Min, Max> of the whole tree.
  std::pair<std::optional<int>, std::optional<int>> backtrack_(TreeNode *Root) {
    if (!Root) {
      return {};
    }

    std::optional<int> MinOpt, MaxOpt;
    auto [LeftMinOpt, LeftMaxOpt] = backtrack_(Root->left);
    auto [RightMinOpt, RightMaxOpt] = backtrack_(Root->right);
    if (LeftMinOpt && RightMinOpt) {
      MinOpt = std::min(*LeftMinOpt, *RightMinOpt);
    } else if (LeftMinOpt) {
      MinOpt = *LeftMinOpt;
    } else if (RightMinOpt) {
      MinOpt = *RightMinOpt;
    }

    if (LeftMaxOpt && RightMaxOpt) {
      MaxOpt = std::max(*LeftMaxOpt, *RightMaxOpt);
    } else if (LeftMaxOpt) {
      MaxOpt = *LeftMaxOpt;
    } else if (RightMaxOpt) {
      MaxOpt = *RightMaxOpt;
    }

    if (MinOpt) {
      Result_ = std::max(Result_, std::abs(*MinOpt - Root->val));
    }
    if (MaxOpt) {
      Result_ = std::max(Result_, std::abs(*MaxOpt - Root->val));
    }
    return {MinOpt ? std::min(*MinOpt, Root->val) : Root->val,
            MaxOpt ? std::max(*MaxOpt, Root->val) : Root->val};
  }
};
