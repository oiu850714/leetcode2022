#include "headers.hpp"

class Solution {
public:
  std::vector<int> plusOne(const std::vector<int> &Digits) {
    auto Ret = Digits;
    std::reverse(Ret.begin(), Ret.end());
    int Carry = 1;
    for (int i = 0; i < Ret.size(); i++) {
      int Sum = (Ret[i] + Carry);
      Ret[i] = Sum % 10;
      Carry = Sum / 10;
    }
    if (Carry == 1) {
      Ret.push_back(1);
    }
    std::reverse(Ret.begin(), Ret.end());
    return Ret;
  }
};
