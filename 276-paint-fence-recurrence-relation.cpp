#include "headers.hpp"

class Solution {
public:
  int numWays(int N, int K) {
    if (N == 1) {
      return K;
    }
    if (N == 2) {
      return K * K;
    }

    int N_minus2 = K, N_minus1 = K * K;
    for (int i = 2; i < N; i++) {
      std::tie(N_minus1, N_minus2) =
          std::pair{(K - 1) * (N_minus1 + N_minus2), N_minus1};
    }
    return N_minus1;
  }
};
