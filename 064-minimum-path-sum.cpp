#include "headers.hpp"

class Solution {
public:
  int minPathSum(std::vector<std::vector<int>> &Grid) {
    std::vector<std::vector<int>> DPTable(Grid.size(),
                                          std::vector<int>(Grid[0].size()));
    // Base cases.
    std::partial_sum(Grid[0].begin(), Grid[0].end(), DPTable[0].begin());
    for (int i = 1; i < DPTable.size(); i++) {
      DPTable[i][0] = DPTable[i - 1][0] + Grid[i][0];
    }

    for (int i = 1; i < DPTable.size(); i++) {
      for (int j = 1; j < DPTable[0].size(); j++) {
        DPTable[i][j] =
            Grid[i][j] + std::min(DPTable[i - 1][j], DPTable[i][j - 1]);
      }
    }
    return DPTable.back().back();
  }
};
