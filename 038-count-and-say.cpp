#include "headers.hpp"

class Solution {
public:
  std::string countAndSay(int N) {
    if (N == 1) {
      return "1";
    }

    auto LastCountStr = countAndSay(N - 1);
    std::string Ret;
    int Count = 1;
    char Curr = LastCountStr[0];
    for (int i = 1; i < LastCountStr.size(); i++) {
      if (LastCountStr[i] == Curr) {
        Count++;
      } else {
        Ret += std::to_string(Count) + Curr;
        Curr = LastCountStr[i];
        Count = 1;
      }
    }
    // Add last portion.
    Ret += std::to_string(Count) + Curr;
    return Ret;
  }
};
