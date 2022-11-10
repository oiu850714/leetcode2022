#include "headers.hpp"

class Solution {
public:
  // "Reverse" of 168., but more intuitive.
  int titleToNumber(std::string ColumnTitle) {
    // Input is guaranteed to be less thant the integer corresponding to
    // "FXSHRXW", i.e. 2^31 - 1.
    // But base may eventually not fit into int, so use int64_t instead.
    int64_t Base = 1;
    int64_t Ret = 0;
    for (int i = ColumnTitle.size() - 1; i >= 0; i--) {
      Ret += Base * (ColumnTitle[i] - 'A' + 1);
      Base *= 26;
    }
    return Ret;
  }
};