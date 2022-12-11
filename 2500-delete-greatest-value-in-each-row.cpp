#include "headers.hpp"

class Solution {
public:
  int deleteGreatestValue(std::vector<std::vector<int>> &Matrix) {
    int Ret = 0;
    for (auto &Row : Matrix) {
      std::sort(Row.begin(), Row.end());
    }
    while (Matrix[0].size()) {
      int Max = 0;
      for (int i = 0; i < Matrix.size(); i++) {
        Max = std::max(Max, Matrix[i].back());
        Matrix[i].pop_back();
      }
      Ret += Max;
    }
    return Ret;
  }
};
