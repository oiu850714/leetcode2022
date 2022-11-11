#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *Root) {
    if (!Root) {
      return {};
    }
    std::vector<TreeNode *> OldQueue, NewQueue;
    std::vector<std::vector<int>> Ret;
    bool IsVisitingNodeRight = true;
    OldQueue.push_back(Root);
    while (!OldQueue.empty()) {
      std::vector<int> NewRow;
      // Invariant: always makes the node order in the OldQueue the desired
      // order.
      for (auto Node : OldQueue) {
        NewRow.push_back(Node->val);
      }
      // But the order of exploring next level nodes will be always reversed.
      // That is, from the last node to the first node in the OldQueue.
      for (int i = OldQueue.size() - 1; i >= 0; i--) {
        auto Node = OldQueue[i];
        // And the order of exploring left or right child depends on the zigzag
        // direction.
        if (IsVisitingNodeRight) {
          if (Node->right) {
            NewQueue.push_back(Node->right);
          }
          if (Node->left) {
            NewQueue.push_back(Node->left);
          }
        } else {
          if (Node->left) {
            NewQueue.push_back(Node->left);
          }
          if (Node->right) {
            NewQueue.push_back(Node->right);
          }
        }
      }
      Ret.push_back(std::move(NewRow));
      OldQueue = std::move(NewQueue);
      IsVisitingNodeRight = !IsVisitingNodeRight;
    }
    return Ret;
  }
};
