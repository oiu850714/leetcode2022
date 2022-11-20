#include "headers.hpp"

class Solution {
public:
  int sumNumbers(TreeNode *Root) {
    // Assume the tree is not empty.
    std::string PathDigits;
    dfs_(Root, PathDigits);
    return Result_;
  }

private:
  int Result_ = 0;

  void dfs_(TreeNode *Node, std::string &PathDigits) {
    PathDigits.push_back(Node->val + '0');

    // Leaf node.
    if (!Node->left && !Node->right) {
      Result_ += std::stoi(PathDigits);
      PathDigits.pop_back();
      return;
    }

    // Else, non leaf node.
    if (Node->left) {
      dfs_(Node->left, PathDigits);
    }
    if (Node->right) {
      dfs_(Node->right, PathDigits);
    }

    PathDigits.pop_back();
  }
};
