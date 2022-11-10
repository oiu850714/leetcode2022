#include "headers.hpp"

class Solution {
public:
  int mySqrt(int X) {
    // Since X <= 2^31 - 1, the square root of X cannot be
    // bigger than ceiling((2^31 - 1)^0.5) == 46341.
    // But 46341^2 will overflow in int, so use int64_t instead.
    int64_t Beg = 0, End = 46341;
    while (Beg < End) {
      auto Mid = Beg + (End - Beg) / 2;
      if (Mid * Mid <= X && (Mid + 1) * (Mid + 1) > X) {
        return Mid;
      } else if (Mid * Mid < X) {
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    return Beg;
  }
};