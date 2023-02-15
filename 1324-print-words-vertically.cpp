#include "headers.hpp"
#include <sstream>

class Solution {
public:
  std::vector<std::string> printVertically(std::string S) {
    int MaxCol = 0;
    std::istringstream ISS(std::move(S));
    std::vector<std::string> Strs;
    std::string Tmp;
    while (ISS >> Tmp) {
      MaxCol = std::max<int>(MaxCol, Tmp.size());
      Strs.push_back(Tmp);
    }

    // visual example
    // s1....
    // s2.......
    // s3.....
    // s4................
    // s5.............
    // s6........
    // s7..........

    std::vector<std::string> Ret(MaxCol);
    for (int j = 0; j < MaxCol; j++) {
      for (int i = 0; i < Strs.size(); i++) {
        Ret[j].push_back(j < Strs[i].size() ? Strs[i][j] : ' ');
      }
    }

    for (auto &VertStr : Ret) {
      while (VertStr.back() == ' ') {
        VertStr.pop_back();
      }
    }

    return Ret;
  }
};
