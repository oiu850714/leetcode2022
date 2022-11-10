#include "headers.hpp"

class Solution {
public:
  int closestValue(TreeNode *Root, double Target) {
    // Assume Root != nullptr.
    auto Curr = Root;
    int Closest = Root->val; // Just give a valid initial value.
    while (Curr) {
      Closest = (std::abs(Closest - Target) < std::abs(Curr->val - Target))
                    ? Closest
                    : Curr->val;
      Curr = Target < Curr->val ? Curr->left : Curr->right;
    }
    return Closest;
  }
};
