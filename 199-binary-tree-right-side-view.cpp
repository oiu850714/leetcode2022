#include "headers.hpp"

class Solution {
public:
  std::vector<int> rightSideView(TreeNode *Root) {
    // Invariant: The two queues store non-null TreeNodes.
    std::vector<TreeNode *> OldQueue, NewQueue;
    std::vector<int> Ret;
    if (Root) {
      OldQueue.push_back(Root);
    }
    while (!OldQueue.empty()) {
      // Push each level's rightmost element into return vector.
      Ret.push_back(OldQueue.back()->val);
      for (auto Node : OldQueue) {
        if (Node->left) {
          NewQueue.push_back(Node->left);
        }
        if (Node->right) {
          NewQueue.push_back(Node->right);
        }
      }
      OldQueue = std::move(NewQueue);
    }
    return Ret;
  }
};