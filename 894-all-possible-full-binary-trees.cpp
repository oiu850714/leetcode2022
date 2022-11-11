#include "headers.hpp"

class Solution {
public:
  std::vector<TreeNode *> allPossibleFBT(int N) {
    return allPossibleFBTRecursive_(N);
  }

private:
  std::vector<TreeNode *> allPossibleFBTRecursive_(int N) {
    if ((N & 1) == 0) {
      return {};
    }
    if (N == 1) {
      // Zero,
      return {new TreeNode{0, nullptr, nullptr}};
    }

    std::vector<TreeNode *> Ret;

    for (int Root = 1; Root <= N; Root++) {
      auto LeftSubtrees = allPossibleFBTRecursive_(Root - 1);
      auto RightSubtrees = allPossibleFBTRecursive_(N - Root);
      for (auto LeftSubtree : LeftSubtrees) {
        for (auto RightSubtree : RightSubtrees) {
          // Or two children.
          TreeNode *Root = new TreeNode{0, LeftSubtree, RightSubtree};
          Ret.push_back(Root);
        }
      }
    }
    return Ret;
  }
};
