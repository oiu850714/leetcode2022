#include "headers.hpp"

#include "1008-construct-binary-search-tree-from-preorder-traversal-monostack.cpp"

using SolutionOf1008OfMonoStack = Solution;

class Codec {
public:
  std::string serialize(TreeNode *Root) {
    if (!Root) {
      return "";
    }

    std::string Ret{std::to_string(Root->val)};
    auto LeftSerialize = serialize(Root->left);
    auto RightSerialize = serialize(Root->right);
    if (!LeftSerialize.empty()) {
      Ret += " " + LeftSerialize;
    }
    if (!RightSerialize.empty()) {
      Ret += " " + RightSerialize;
    }
    return Ret;
  }

  TreeNode *deserialize(const std::string &Data) {
    auto PreorderVals = split_(Data);
    // Reduce to solution of 1008.
    return SolutionOf1008OfMonoStack{}.bstFromPreorder(PreorderVals);
  }

private:
  std::vector<int> split_(const std::string &Data) {
    if (Data.empty()) {
      return {};
    }
    std::vector<int> Ret;
    for (int ValBeg = 0;;) {
      auto ValEnd = Data.find_first_of(" ", ValBeg);
      if (ValEnd == std::string::npos) {
        Ret.push_back(std::stoi(Data.substr(ValBeg)));
        break;
      } else {
        Ret.push_back(std::stoi(Data.substr(ValBeg, ValEnd - ValBeg)));
        ValBeg = ValEnd + 1;
      }
    }
    return Ret;
  }
};
