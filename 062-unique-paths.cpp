#include "headers.hpp"

class Solution {
public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> DPTable(m, std::vector<int>(n));
    // Base case
    for (int i = 0; i < m; i++) {
      DPTable[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
      DPTable[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        DPTable[i][j] = DPTable[i - 1][j] + DPTable[i][j - 1];
      }
    }
    return DPTable[m - 1][n - 1];
  }
};