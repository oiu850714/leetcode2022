#include "headers.hpp"

class Solution {
public:
  int longestCommonSubsequence(std::string S1, std::string S2) {
    const int L1 = S1.size(), L2 = S2.size();
    std::vector<std::vector<int>> DPTable(L1, std::vector<int>(L2));

    // Base cases.
    DPTable[0][0] = (S1[0] == S2[0]);
    // S1[0] and all prefices of S2.
    for (int j = 1; j < L2; j++) {
      DPTable[0][j] = DPTable[0][j - 1] || S1[0] == S2[j];
    }
    // All prefices of S1 and S2[0].
    for (int i = 1; i < L1; i++) {
      DPTable[i][0] = DPTable[i - 1][0] || S1[i] == S2[0];
    }

    for (int i = 1; i < L1; i++) {
      for (int j = 1; j < L2; j++) {
        if (S1[i] == S2[j]) {
          DPTable[i][j] = DPTable[i - 1][j - 1] + 1;
        } else {
          DPTable[i][j] = std::max(DPTable[i - 1][j], DPTable[i][j - 1]);
        }
      }
    }
    return DPTable[L1 - 1][L2 - 1];
  }
};
