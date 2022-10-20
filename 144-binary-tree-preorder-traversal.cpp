#include "headers.hpp"

class Solution {
public:
  std::vector<int> preorderTraversal(TreeNode *Root) {
    preorderTraversalRecursive(Root);
    return std::move(Result);
  }

private:
  void preorderTraversalRecursive(TreeNode *Root) {
    if (!Root) {
      return;
    }
    Result.push_back(Root->val);
    preorderTraversalRecursive(Root->left);
    preorderTraversalRecursive(Root->right);
  }
  std::vector<int> Result;
};