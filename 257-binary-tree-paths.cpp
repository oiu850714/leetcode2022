#include "headers.hpp"

class Solution {
public:
  std::vector<std::string> binaryTreePaths(TreeNode *Root) {
    std::vector<int> Path{Root->val};
    backtrack_(Root, Path);
    return std::move(Result_);
  }

private:
  std::vector<std::string> Result_;

  // Assume Node != nullptr.
  void backtrack_(TreeNode *Node, std::vector<int> &Path) {
    if (!Node->left && !Node->right) {
      Result_.push_back(convertPath_(Path));
      return;
    }

    if (Node->left) {
      Path.push_back(Node->left->val);
      backtrack_(Node->left, Path);
      Path.pop_back(); // Restore state.
    }
    if (Node->right) {
      Path.push_back(Node->right->val);
      backtrack_(Node->right, Path);
      Path.pop_back(); // Restore state.
    }
  }

  // Assume Path.size() >= 1.
  std::string convertPath_(const std::vector<int> &Path) {
    std::string Ret;
    Ret += std::to_string(Path[0]);
    for (size_t i = 1; i < Path.size(); i++) {
      Ret += "->" + std::to_string(Path[i]);
    }
    return Ret;
  }
};
