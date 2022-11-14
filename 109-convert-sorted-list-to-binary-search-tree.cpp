#include "headers.hpp"

class Solution {
public:
  TreeNode *sortedListToBST(ListNode *Head) {
    if (!Head) {
      return nullptr;
    }

    auto NumNodes = getNumNodes(Head);
    return inorderBuildTree_(Head, NumNodes).first;
  }

private:
  int getNumNodes(ListNode *Head) {
    int Ret = 0;
    while (Head) {
      Head = Head->next;
      Ret++;
    }
    return Ret;
  }

  std::pair<TreeNode *, ListNode *> inorderBuildTree_(ListNode *ListHead,
                                                      int NumNodes) {
    if (NumNodes == 0) {
      return {nullptr, ListHead};
    }

    int NumLeftTreeNodes = NumNodes >> 1,
        NumRightTreeNodes = NumNodes - NumLeftTreeNodes - 1;
    auto [LeftTree, ListMiddle] = inorderBuildTree_(ListHead, NumLeftTreeNodes);
    auto [RightTree, ListLast] =
        inorderBuildTree_(ListMiddle->next, NumRightTreeNodes);
    TreeNode *Root = new TreeNode(ListMiddle->val, LeftTree, RightTree);
    return {Root, ListLast};
  }
};
