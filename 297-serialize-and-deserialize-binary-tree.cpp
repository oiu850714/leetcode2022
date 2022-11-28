#include "headers.hpp"

class Codec {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *Root) {
    if (!Root) {
      return "n";
    }

    std::string Ret{std::to_string(Root->val)};
    Ret += " " + serialize(Root->left) + " " + serialize(Root->right);
    return Ret;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(const std::string &Data) {
    return deserialRecursive_(Data, 0).first;
  }

private:
  // Node, Deserialized end
  std::pair<TreeNode *, int> deserialRecursive_(const std::string &Data,
                                                int BegIdx) {
    if (Data[BegIdx] == 'n') {
      return {nullptr, BegIdx + 1};
    }

    int RootVal = 0;
    auto SpaceIdx = Data.find_first_of(" ", BegIdx);
    RootVal = std::stoi(Data.substr(BegIdx, SpaceIdx - BegIdx));
    auto Root = new TreeNode(RootVal);
    auto [Left, LeftEnd] = deserialRecursive_(Data, SpaceIdx + 1);
    auto [Right, RightEnd] = deserialRecursive_(Data, LeftEnd + 1);
    Root->left = Left;
    Root->right = Right;
    return {Root, RightEnd};
  }
};
