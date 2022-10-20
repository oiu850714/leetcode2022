#include "headers.hpp"

class Solution {
public:
  std::vector<int> postorderTraversal(TreeNode *Root) {
    postorderTraversalRecursive(Root);
    return std::move(Result);
  }

private:
  void postorderTraversalRecursive(TreeNode *Root) {
    if (!Root) {
      return;
    }
    postorderTraversalRecursive(Root->left);
    postorderTraversalRecursive(Root->right);
    Result.push_back(Root->val);
  }
  std::vector<int> Result;
};