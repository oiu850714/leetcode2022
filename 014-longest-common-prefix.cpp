#include "headers.hpp"

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string> &Strs) {
    std::string Ret;
    for (auto i = 0; true; i++) {
      char c = '0'; // Use the assumption that the strings only contain
                    // lowercase letters. So we can use a digit to represent
                    // "uninitialized" state.
      for (const auto &Str : Strs) {
        if (i >= Str.size()) {
          return Ret;
        }
        if (!std::islower(c)) {
          c = Str[i];
        } else if (c != Str[i]) {
          return Ret;
        }
      }
      Ret.push_back(c);
    }
  }
};