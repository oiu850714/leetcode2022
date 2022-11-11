#include "headers.hpp"

class Solution {
public:
  int longestZigZag(TreeNode *Root) {
    zigZag(Root);
    return MaxLen_;
  }

  // Return:
  // 1. Max length of first-zig and first-zag path starting from root,
  // respectively.
  std::tuple<int, int> zigZag(TreeNode *Root) {
    if (!Root) {
      return {0, 0};
    }

    int LeftChildZagLen = 0;
    int RightChildZigLen = 0;
    int DontCare = 0;
    int RootZigLen = 0, RootZagLen = 0;
    if (Root->left) {
      std::tie(DontCare, LeftChildZagLen) = zigZag(Root->left);
      RootZigLen = LeftChildZagLen + 1;
      MaxLen_ = std::max(MaxLen_, RootZigLen);
    }
    if (Root->right) {
      std::tie(RightChildZigLen, DontCare) = zigZag(Root->right);
      RootZagLen = RightChildZigLen + 1;
      MaxLen_ = std::max(MaxLen_, RootZagLen);
    }
    return {RootZigLen, RootZagLen};
  }

private:
  int MaxLen_ = 0;
};
