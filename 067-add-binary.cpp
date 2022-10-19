#include "headers.hpp"

class Solution {
public:
  std::string addBinary(std::string A, std::string B) {
    std::string Ret;
    auto AIter = A.crbegin(), BIter = B.crbegin();
    int Carry = 0;
    int Result = 0;
    while (AIter != A.crend() && BIter != B.crend()) {
      std::tie(Carry, Result) =
          carrayAndResult((*AIter++ - '0') + (*BIter++ - '0') + Carry);
      Ret.push_back(Result + '0');
    }
    if (AIter != A.crend()) {
      while (AIter != A.crend()) {
        std::tie(Carry, Result) = carrayAndResult((*AIter++ - '0') + Carry);
        Ret.push_back(Result + '0');
      }
    } else if (BIter != B.crend()) {
      while (BIter != B.crend()) {
        std::tie(Carry, Result) = carrayAndResult((*BIter++ - '0') + Carry);
        Ret.push_back(Result + '0');
      }
    }
    if (Carry == 1) {
      Ret.push_back('1');
    }
    std::reverse(Ret.begin(), Ret.end());
    return Ret;
  }
  std::pair<int, int> carrayAndResult(int Value) {
    int Carry = Value >> 1;
    int Result = Value & 1;
    return {Carry, Result};
  }
};