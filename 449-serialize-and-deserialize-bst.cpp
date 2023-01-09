#include "headers.hpp"

#include <sstream>

class Codec {
public:
  std::string serialize(TreeNode *Root) {
    if (!Root) {
      return "";
    }
    auto LeftSerialized = serialize(Root->left);
    auto RightSerialized = serialize(Root->right);
    auto RootVal = std::to_string(Root->val);

    return RootVal + (LeftSerialized.empty() ? "" : " ") + LeftSerialized +
           (RightSerialized.empty() ? "" : " ") + RightSerialized;
  }

  TreeNode *deserialize(const std::string &Data) {
    auto Nums = toNums_(Data);
    auto NGEIdx = toNGEIdx_(Nums);

    return deserializeRecursive_(0, Nums.size(), Nums, NGEIdx);
  }

private:
  std::vector<int> toNums_(const std::string &Data) {
    std::vector<int> Ret;

    std::istringstream ISS(Data);
    int Num = 0;
    while (ISS >> Num) {
      Ret.push_back(Num);
    }
    return Ret;
  }

  // Next Greater Element
  std::vector<int> toNGEIdx_(const std::vector<int> &Nums) {
    std::vector<int> NGE(Nums.size(), Nums.size());
    std::stack<int> Stack;
    for (size_t i = 0; i < Nums.size(); i++) {
      while (!Stack.empty() && Nums[Stack.top()] < Nums[i]) {
        NGE[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }
    return NGE;
  }

  TreeNode *deserializeRecursive_(size_t Beg, size_t End,
                                  const std::vector<int> &Nums,
                                  const std::vector<int> &NGEIdx) {
    if (Beg == End) {
      return nullptr;
    }
    return new TreeNode(
        Nums[Beg], deserializeRecursive_(Beg + 1, NGEIdx[Beg], Nums, NGEIdx),
        deserializeRecursive_(NGEIdx[Beg], End, Nums, NGEIdx));
  }
};
