#include "headers.hpp"

class Solution {
public:
  // The "interleaving" criteria is just "irrelevant" if we pick "single char
  // string" in S1 and S2.
  // Then by combining "adjacent-same-string-characters" the result is a
  // interleaving of S1 and S2.
  bool isInterleave(std::string S1, std::string S2, std::string S) {
    if (S1.size() + S2.size() != S.size()) {
      return false;
    }

    // Again, notice the offset by 1 of indices calculation.
    std::vector<std::vector<bool>> DPTable(S1.size() + 1,
                                           std::vector<bool>(S2.size() + 1));
    DPTable[0][0] = true;
    for (int i = 1; i <= S1.size(); i++) {
      DPTable[i][0] = DPTable[i - 1][0] && S[i - 1] == S1[i - 1];
    }
    for (int j = 1; j <= S2.size(); j++) {
      DPTable[0][j] = DPTable[0][j - 1] && S[j - 1] == S2[j - 1];
    }

    for (int i = 1; i <= S1.size(); i++) {
      for (int j = 1; j <= S2.size(); j++) {
        auto SLast = S[i + j - 1], S1Last = S1[i - 1], S2Last = S2[j - 1];
        DPTable[i][j] = (SLast == S1Last && DPTable[i - 1][j]) ||
                        (SLast == S2Last && DPTable[i][j - 1]);
      }
    }
    return DPTable.back().back();
  }
};
