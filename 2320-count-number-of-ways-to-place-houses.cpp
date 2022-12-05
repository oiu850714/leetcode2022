#include "headers.hpp"

class Solution {
public:
  int countHousePlacements(int N) {
    // Essentially a fib seq.
    constexpr int Mod = 1000000007;
    int64_t DPPrevPrev = 1, DPPrev = 2;
    for (int i = 2; i <= N; i++) {
      std::tie(DPPrevPrev, DPPrev) = std::pair{DPPrev, DPPrevPrev + DPPrev};
      DPPrevPrev %= Mod;
      DPPrev %= Mod;
    }
    return (DPPrev * DPPrev) % Mod;
  }
};
