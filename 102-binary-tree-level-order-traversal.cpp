#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *Root) {
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
