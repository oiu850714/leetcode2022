#include "headers.hpp"

class Solution {
  // BTW the test case causes the prefix sum temporarily to be larger than
  // INT_MAX, so use int64_t to represent prefix sum instead.
public:
  int pathSum(TreeNode *Root, int TargetSum) {
    TargetSum_ = TargetSum;
    int64_t InitialPrefixSum = 0;
    pathSumRecursive(Root, InitialPrefixSum);
    return TotalCount_;
  }

private:
  int64_t TargetSum_ =
      0; //  Just prevent path the target sum in each recursive call.
  std::unordered_map<int64_t, int>
      AncestorPrefixSumCount; // Always store the prefix sums of all the (valid)
                              // ancestors of the current node.
  int TotalCount_ = 0;

  void pathSumRecursive(TreeNode *Node, int64_t CurrentPrefixSum) {
    if (!Node) {
      return;
    }
    // The whole process is "preorder"-traversal: Node, Node->left, Node->right.
    CurrentPrefixSum += Node->val;
    if (CurrentPrefixSum == TargetSum_) {
      // The prefix sum from Root to this Node is equal to TargetSum_
      TotalCount_++;
    }
    // The total count calculation logic is similar to 560.
    auto RemainSum = CurrentPrefixSum - TargetSum_;
    if (AncestorPrefixSumCount.find(RemainSum) !=
        AncestorPrefixSumCount.end()) {
      TotalCount_ += AncestorPrefixSumCount.at(RemainSum);
    }
    AncestorPrefixSumCount[CurrentPrefixSum]++;
    pathSumRecursive(Node->left, CurrentPrefixSum);
    pathSumRecursive(Node->right, CurrentPrefixSum);
    // The difference is we need to "remove" the prefix sum corresponding to
    // this Node at the end.
    AncestorPrefixSumCount[CurrentPrefixSum]--;
  }
};