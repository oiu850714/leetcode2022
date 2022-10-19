#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    // essentially a BFS
    std::vector<std::vector<int>> Ret;
    // store node and level
    std::queue<std::pair<TreeNode *, int>> Frontier;
    Frontier.push({root, 0});
    while (!Frontier.empty()) {
      auto [Node, Level] = Frontier.front();
      Frontier.pop();
      if (!Node) {
        continue;
      }
      if (Ret.size() < Level + 1) {
        Ret.push_back({});
      }
      Ret[Level].push_back(Node->val);
      Frontier.push({Node->left, Level + 1});
      Frontier.push({Node->right, Level + 1});
    }
    return Ret;
  }
};