#include "headers.hpp"

class Solution {
public:
  std::vector<TreeNode *> generateTrees(int N) {
    return buildTreeRecursive(1, N);
  }

  std::vector<TreeNode *> buildTreeRecursive(int FirstValue, int NumElements) {
    if (NumElements == 0) {
      return {nullptr};
    }
    if (NumElements == 1) {
      return {new TreeNode{FirstValue, nullptr, nullptr}};
    }
    std::vector<TreeNode *> Ret;
    auto LastValue = FirstValue + NumElements - 1;
    for (int RootValue = FirstValue; RootValue <= LastValue; RootValue++) {
      int NumLeftTreeNodes = RootValue - FirstValue;
      int NumRightTreeNodes = LastValue - RootValue;
      auto AllLeftSubTrees = buildTreeRecursive(FirstValue, NumLeftTreeNodes);
      auto AllRightSubTrees =
          buildTreeRecursive(RootValue + 1, NumRightTreeNodes);
      for (int i = 0; i < AllLeftSubTrees.size(); i++) {
        for (int j = 0; j < AllRightSubTrees.size(); j++) {
          Ret.push_back(
              new TreeNode(RootValue, AllLeftSubTrees[i], AllRightSubTrees[j]));
        }
      }
    }
    return Ret;
  }
};