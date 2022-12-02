#include "headers.hpp"

class Solution {
public:
  int reverse(int Num) {
    bool IsNegative = Num < 0;
    // Note that Num maybe -2^31 - 1, whose absolute value will overflow on int.
    if (Num == std::numeric_limits<int>::min()) {
      // -2147483648
      // The reverse of this int is also overflow on int, so return 0.
      return 0;
    }

    // Now convert Num to its abs won't cause any overflow.
    Num = std::abs(Num);

    // Remove trailing zero.
    // e.g. 123000 -> 123, which has 321 as its revered integer.
    while (Num > 0 && Num % 10 == 0) {
      Num /= 10;
    }
    int Ret = 0;
    while (Num > 0) {
      // Each if statement checks when the conversion will overflow on int.
      if (Ret > std::numeric_limits<int>::max() / 10) {
        return 0;
      }
      Ret *= 10;
      if (Ret > std::numeric_limits<int>::max() - (Num % 10)) {
        return 0;
      }
      Ret += Num % 10;
      Num /= 10;
    }
    return IsNegative ? -Ret : Ret;
  }
};
