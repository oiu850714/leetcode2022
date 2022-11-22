#include "headers.hpp"

class Solution {
public:
  int numDistinct(std::string S, std::string T) {
    if (S.size() < T.size()) {
      return 0;
    }

    // Assume both S, T are nonempty.

    // DPTable[i][j] is the solution of T.substr(0, i) and S.substr(0, j).
    // WARNING: the solution of the original problem is < 2^31 - 1, but the
    // solution of subproblem may still overflow on int.
    // The all the test cases DO FIT in uint32_t, so use uint32_t instead.
    std::vector<std::vector<uint32_t>> DPTable(T.size(),
                                               std::vector<uint32_t>(S.size()));

    DPTable[0][0] = T[0] == S[0];
    // Base case: T.substr(0, 1) and all prefices of S.
    for (int j = 1; j < S.size(); j++) {
      DPTable[0][j] = DPTable[0][j - 1] + (T[0] == S[j]);
    }

    for (int i = 1; i < T.size(); i++) {
      // Notice the starting index of j;
      // If the prefix of S (represted by j) is shorter than the prefix of T
      // (represted by i), then the corresponding solution must be zero, so we
      // can skip the check.
      for (int j = i; j < S.size(); j++) {
        DPTable[i][j] = DPTable[i][j - 1];
        if (T[i] == S[j]) {
          DPTable[i][j] += DPTable[i - 1][j - 1];
        }
      }
    }

    return DPTable[T.size() - 1][S.size() - 1];
  }
};
