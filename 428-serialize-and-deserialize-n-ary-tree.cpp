#include "headers.hpp"
#include <sstream>
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

class Codec {
public:
  std::string serialize(Node *Root) {
    if (!Root) {
      return "";
    }

    std::string Ret{std::to_string(Root->val) + " " +
                    std::to_string(Root->children.size())};
    for (auto Child : Root->children) {
      Ret += " " + serialize(Child);
    }
    return Ret;
  }

  Node *deserialize(const std::string &Data) {
    std::istringstream ISS(Data);
    return deserialRecursive_(ISS);
  }

  Node *deserialRecursive_(std::istringstream &ISS) {
    // Very convenient usage for sstream:
    // 1. Automatically parse the data.
    // 2. IMPORTANT: Effectively record the current parsing position of the
    // data.
    auto NodeVal = 0, NumChildren = 0;
    if (ISS >> NodeVal >> NumChildren) {
      auto Ret = new Node(NodeVal);
      for (int i = 0; i < NumChildren; i++) {
        Ret->children.push_back(deserialRecursive_(ISS));
      }
      return Ret;
    } else {
      return nullptr;
    }
  }
};
