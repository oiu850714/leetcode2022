#include "headers.hpp"

class Solution {
public:
  std::vector<int> preorder(Node *Root) {
    std::vector<int> Ret;
    preOrderRecursive(Root, Ret);
    return Ret;
  }

private:
  void preOrderRecursive(Node *Root, std::vector<int> &Result) {
    if (Root == nullptr)
      return;

    Result.push_back(Root->val);
    for (auto Child : Root->children) {
      preOrderRecursive(Child, Result);
    }
  }
};