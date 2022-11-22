#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode *Root) {
    auto LevelOrder = levelOrder_(Root);
    // Just reverse the solution of ordinary level order traversal.
    std::reverse(LevelOrder.begin(), LevelOrder.end());
    return LevelOrder;
  }

private:
  // Copied from 102.
  std::vector<std::vector<int>> levelOrder_(TreeNode *Root) {
    std::vector<std::vector<int>> Ret;
    std::vector<TreeNode *> Queue{Root};
    while (!Queue.empty()) {
      std::vector<TreeNode *> NextQueue;
      std::vector<int> NewLevelValues;
      for (auto Node : Queue) {
        if (Node) {
          NewLevelValues.push_back(Node->val);
          NextQueue.push_back(Node->left);
          NextQueue.push_back(Node->right);
        }
      }
      Queue.swap(NextQueue);
      if (!NewLevelValues.empty()) {
        Ret.push_back(std::move(NewLevelValues));
      }
    }
    return Ret;
  }
};
