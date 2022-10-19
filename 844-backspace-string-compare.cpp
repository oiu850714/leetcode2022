#include "headers.hpp"

class Solution {
public:
  // TODO: O(1) space
  bool backspaceCompare(std::string S, std::string T) {
    return typeString(S) == typeString(T);
  }

private:
  std::string typeString(std::string S) {
    std::string Ret;
    for (auto i = 0; i < S.size(); i++) {
      if (S[i] != '#') {
        Ret.push_back(S[i]);
      } else if (!Ret.empty()) {
        Ret.pop_back();
      }
    }
    return Ret;
  }
};