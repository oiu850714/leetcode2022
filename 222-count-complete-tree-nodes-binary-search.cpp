#include "headers.hpp"

class Solution {
public:
  int countNodes(TreeNode *Root) {
    if (!Root) {
      return 0;
    }
    int Height = getLeftHeight_(Root);
    auto Beg = toOrder_(Height), End = 2 * Beg;
    while (Beg < End) {
      auto Mid = Beg + (End - Beg) / 2;
      if (nodeOfOrderExists_(Root, Mid)) {
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    // Beg will be the order of the first nonexistant node in the last level.
    return Beg - 1;
  }

  int getLeftHeight_(TreeNode *Root) {
    int Ret = -1;
    while (Root) {
      Ret++;
      Root = Root->left;
    }
    return Ret;
  }

  int toOrder_(int Height) {
    assert(Height >= 0 && Height <= 16);
    constexpr static std::array Order{1,    2,    4,     8,     16,   32,
                                      64,   128,  256,   512,   1024, 2048,
                                      4096, 8192, 16384, 32768, 65536};
    return Order[Height];
  }

  bool nodeOfOrderExists_(TreeNode *Root, int Order) {
    if (Order == 1) {
      return true;
    }

    // I'm not good at binary manipulation.
    std::vector<bool> PathSelections;
    while (Order != 1) {
      PathSelections.push_back(Order & 1);
      Order >>= 1;
    }
    std::reverse(PathSelections.begin(), PathSelections.end());

    auto Curr = Root;
    for (int i = 0; i < PathSelections.size() && Curr; i++) {
      Curr = PathSelections[i] ? Curr->right : Curr->left;
    }
    return Curr != nullptr;
  }
};
