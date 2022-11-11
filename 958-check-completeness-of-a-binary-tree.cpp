#include "headers.hpp"

class Solution {
public:
  bool isCompleteTree(TreeNode *Root) {
    std::vector<TreeNode *> OldQueue, NewQueue;
    size_t NextLevelFullNumber = 2;
    OldQueue.push_back(Root);

    while (!OldQueue.empty()) {
      bool HasSeenNullChild = false;
      size_t NextLevelNodeCount = 0;
      for (auto Node : OldQueue) {
        if (Node->left) {
          if (HasSeenNullChild) {
            return false;
          }
          NextLevelNodeCount++;
          NewQueue.push_back(Node->left);
        } else {
          HasSeenNullChild = true;
        }
        if (Node->right) {
          if (HasSeenNullChild) {
            return false;
          }
          NextLevelNodeCount++;
          NewQueue.push_back(Node->right);
        } else {
          HasSeenNullChild = true;
        }
      }
      OldQueue = std::move(NewQueue);
      if (NextLevelNodeCount == NextLevelFullNumber) {
        NextLevelFullNumber *= 2;
      } else {
        // New OldQueue contains nodes in LAST non-full level.
        break;
      }
    }
    if (!OldQueue.empty()) {
      for (auto Node : OldQueue) {
        if (Node->left || Node->right) {
          return false;
        }
      }
    }
    return true;
  }
};
