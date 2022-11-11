#include "headers.hpp"

class Solution {
public:
  // I need a proof for this implementation:
  // Statement: A tree is complete if and only if isCompleteTree returns true.
  // => This direction is OK to me.
  // <= Proof by contradiction. Suppose algo returns true but the tree is NOT
  // complete.
  //    By def of complete tree, the non-cmplete tree has more than one levels
  //    of non-full nodes, or its nodes in the last level are not as far left as
  //    possible.
  //        For the first case, when traversing the first non-full level, the
  //        algo sets HasSeenNullChild to true. And if the algo does not return
  //        false and still algo goes to the next level(there must exist another
  //        level, since there exists at least one another non-full level), it
  //        will return false because it will see a node. So we get
  //        contradiction.
  //
  //        For the second case, of course the algo return false when it
  //        traverse the last non-full level with some nodes not as far left as
  //        possible.
  //    So in all cases we get contradictions, to the tree must be complete.
  bool isCompleteTree(TreeNode *Root) {
    std::vector<TreeNode *> OldQueue, NewQueue;
    bool HasSeenNullChild = false;
    OldQueue.push_back(Root);

    while (!OldQueue.empty()) {
      for (auto Node : OldQueue) {
        if (!Node) {
          HasSeenNullChild = true;
        } else {
          if (HasSeenNullChild) {
            return false;
          }
          NewQueue.push_back(Node->left);
          NewQueue.push_back(Node->right);
        }
      }
      OldQueue = std::move(NewQueue);
    }
    return true;
  }
};
