#include "headers.hpp"

class Solution {
public:
  bool leafSimilar(TreeNode *R1, TreeNode *R2) {
    return dumpLeaves_(R1) == dumpLeaves_(R2);
  }

private:
  std::vector<int> dumpLeaves_(TreeNode *Root) {
    std::vector<int> Ret;
    dumpLeavesRecursive_(Root, Ret);
    return Ret;
  }

  void dumpLeavesRecursive_(TreeNode *Root, std::vector<int> &Ret) {
    if (!Root) {
      return;
    }

    if (!Root->left && !Root->right) {
      Ret.push_back(Root->val);
      return;
    }
    dumpLeavesRecursive_(Root->left, Ret);
    dumpLeavesRecursive_(Root->right, Ret);
  }
};
