#include "headers.hpp"

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

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