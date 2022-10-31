#include "headers.hpp"

class Solution {
public:
  int widthOfBinaryTree(TreeNode *Root) {
    // By assumption, Root must be non-nullptr.
    std::vector<std::pair<TreeNode *, uint64_t>> OldFrontier, NewFrontier;
    // The second element represents the index of the node, pretending the Tree
    // is a complete binary tree.
    // With that assumption and the index is "1-based", if a node is index K,
    // then it's left child has index 2K, it's right child has index 2K + 1.
    // (Just similar to the rule of heap index calculation.)
    OldFrontier.push_back({Root, 1});

    // WARNING: the test cases in leetcode has some index that is greater than
    // int64_t, so use uint64_t instead.
    uint64_t MaxWidth = 1;
    while (!OldFrontier.empty()) {
      auto [LeftMost, LeftIndex] = OldFrontier.front();
      auto [RightMost, RightIndex] = OldFrontier.back();
      MaxWidth = std::max<uint64_t>(MaxWidth, RightIndex - LeftIndex + 1);

      for (auto [Node, Index] : OldFrontier) {
        if (Node->left) {
          NewFrontier.push_back({Node->left, Index * 2});
        }
        if (Node->right) {
          NewFrontier.push_back({Node->right, Index * 2 + 1});
        }
      }

      OldFrontier = std::move(NewFrontier);
    }
    return MaxWidth;
  }
};