#include "headers.hpp"

class Solution {
public:
  int trailingZeroes(int N) {
    auto AnotherFives = 0;
    if (N >= 25) {
      AnotherFives += N / 25;
    }
    if (N >= 125) {
      AnotherFives += N / 125;
    }
    if (N >= 625) {
      AnotherFives += N / 625;
    }
    if (N >= 3125) {
      AnotherFives += N / 3125;
    }
    return N / 5 + AnotherFives;
  }
};