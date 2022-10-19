#include "headers.hpp"

class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *Root) {
    inorderTraversalRecursive(Root);
    return std::move(Result);
  }

private:
  std::vector<int> Result;

  void inorderTraversalRecursive(TreeNode *Node) {
    if (!Node) {
      return;
    }
    inorderTraversalRecursive(Node->left);
    Result.push_back(Node->val);
    inorderTraversalRecursive(Node->right);
  }
};