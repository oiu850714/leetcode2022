#include "headers.hpp"

class Solution {
public:
  int minDistance(const std::string W1, const std::string W2) {
    // DPTable[i][j] store #operations to convert W1[0, j) to W2[0, i).
    std::vector<std::vector<int>> DPTable(W2.size() + 1,
                                          std::vector<int>(W1.size() + 1));
    for (int i = 0; i <= W2.size(); i++) {
      DPTable[i][0] = i;
    }
    for (int j = 0; j <= W1.size(); j++) {
      DPTable[0][j] = j;
    }
    for (int i = 1; i <= W2.size(); i++) {
      for (int j = 1; j <= W1.size(); j++) {
        auto LastCharMatch = std::numeric_limits<int>::max();
        // Notice the offset-by-one of indices of W1 W2 and DPTable.
        if (W2[i - 1] == W1[j - 1]) {
          LastCharMatch = DPTable[i - 1][j - 1];
        }
        auto ReplaceW1_j_to_W2_i = DPTable[i - 1][j - 1] + 1;
        auto InsertW2_i_to_W1 = DPTable[i - 1][j] + 1;
        auto DeleteW1_j = DPTable[i][j - 1] + 1;
        DPTable[i][j] = std::min(
            {LastCharMatch, ReplaceW1_j_to_W2_i, InsertW2_i_to_W1, DeleteW1_j});

        // In fact, if the last character is a match, then DP entry is just
        // DP[i-1][j-1]. But I cannot find the proof that the other three
        // --- precisely, the last two, since ReplaceW1_j_to_W2_i must >
        // DP[i-1][j-1] --- options must be >= DP[i-1][j-1].
        // So I just take the minimum of all of them as DP[i][j].
      }
    }
    return DPTable.back().back();
  }
};
