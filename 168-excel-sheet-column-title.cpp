#include "headers.hpp"

class Solution {
public:
  std::string convertToTitle(int ColumnNumber) {
    std::string Ret;
    while (ColumnNumber > 0) {
      char Digit = ColumnNumber % 26 + 'A';
      // Since ColumnNumber is still > 0, if Digit is a multiple of 26, the rule
      // is use the last digit as 'Z' to represent this one of this multiple
      // of 26.
      // e.g. 26 -> Z, 52 -> AZ, 78 -> BZ.
      if (Digit == 'A') {
        Digit = 'Z';
        ColumnNumber -= 26;
      } else {
        // Otherwise, the last digit is in 1 ~ 25.
        // But we need to shift one character back from "normal" base
        // conversion. e.g. In the normal case, If last number is 1, it
        // corresponds to 'B', but in this system, we should use 'A' (i.e. shift
        // 'B' one character back to 'A') represents 1 instead.
        Digit -= 1;
      }
      ColumnNumber /= 26;
      Ret.push_back(Digit);
    }
    std::reverse(Ret.begin(), Ret.end());
    return Ret;
  }
};