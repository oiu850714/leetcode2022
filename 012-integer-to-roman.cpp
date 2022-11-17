#include "headers.hpp"

static constexpr std::array UnitMap{"",  "I",  "II",  "III",  "IV",
                                    "V", "VI", "VII", "VIII", "IX"};
static constexpr std::array TensMap{"",  "X",  "XX",  "XXX",  "XL",
                                    "L", "LX", "LXX", "LXXX", "XC"};
static constexpr std::array HunsMap{"",  "C",  "CC",  "CCC",  "CD",
                                    "D", "DC", "DCC", "DCCC", "CM"};
static constexpr std::array ThousMap{"", "M", "MM", "MMM"};
class Solution {
public:
  std::string intToRoman(int Num) {
    if (Num >= 4000 || Num <= 0) {
      // Input is guaranteed to be 1 ~ 3999, just prevent out-of-range UB.
      return "";
    }
    int UnitDigit = Num % 10;
    Num /= 10;
    int TensDigit = Num % 10;
    Num /= 10;
    int HunsDigit = Num % 10;
    Num /= 10;
    int ThousDigit = Num % 10;
    return std::string(ThousMap[ThousDigit]) + HunsMap[HunsDigit] +
           TensMap[TensDigit] + UnitMap[UnitDigit];
  }
};
