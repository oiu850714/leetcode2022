#include "headers.hpp"

class Solution {
public:
  int numDistinct(std::string S, std::string T) {
    if (S.size() < T.size()) {
      return 0;
    }

    // Assume both S, T are nonempty.

    // From the basic solution, each entry only depends:
    // 1. the left entry.
    // 2. the up-left entry.
    // So we only need to store the previous row of DP table.
    std::vector<uint32_t> DPRow(S.size()), DPNewRow(S.size());
    // The DPNewRow is used to swap with DPRow at every iteration, to prevent
    // allocating new vector again and again.

    DPRow[0] = T[0] == S[0];
    // Base case: T.substr(0, 1) and all prefices of S.
    for (int j = 1; j < S.size(); j++) {
      DPRow[j] = DPRow[j - 1] + (T[0] == S[j]);
    }

    for (int i = 1; i < T.size(); i++) {
      // Notice the starting index of j;
      // If the prefix of S (represted by j) is shorter than the prefix of T
      // (represted by i), then the corresponding solution must be zero, so we
      // can skip the check.
      for (int j = i; j < S.size(); j++) {
        DPNewRow[j] = DPNewRow[j - 1]; // Left entry in basic solution.
        if (T[i] == S[j]) {
          DPNewRow[j] += DPRow[j - 1]; // Up-left entry in basic solution.
        }
      }

      // Just some implementation details.
      DPRow.swap(DPNewRow);
      std::fill(DPNewRow.begin(), DPNewRow.end(), 0);
    }

    return DPRow.back();
  }
};
