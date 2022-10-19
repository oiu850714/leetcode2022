#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> pathSum(TreeNode *Root, int TargetSum) {
    if (!Root) {
      // empty tree by definition "does not have" a non-empty root-to-leaf path.
      return {};
    }

    if (!Root->left && !Root->right) {
      if (TargetSum == Root->val) {
        return {{TargetSum}};
      } else {
        return {};
      }
    }

    int SubTargetSum = TargetSum - Root->val;
    auto LeftPathSum = pathSum(Root->left, SubTargetSum);
    auto RightPathSum = pathSum(Root->right, SubTargetSum);
    std::vector<std::vector<int>> Ret;
    // We need to return the path in the order from the root to the leaf, so we
    // need to insert the Root->val first, and insert the remaing subpath after
    // that value.
    // Just use STL API.
    for (const auto &Path : LeftPathSum) {
      Ret.push_back({Root->val});
      Ret.back().insert(Ret.back().end(), Path.begin(), Path.end());
    }
    for (const auto &Path : RightPathSum) {
      Ret.push_back({Root->val});
      Ret.back().insert(Ret.back().end(), Path.begin(), Path.end());
    }
    return Ret;
  }
};