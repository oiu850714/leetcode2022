#include "headers.hpp"

class Solution {
public:
  int uniquePathsWithObstacles(std::vector<std::vector<int>> &ObstacleGrid) {
    int M = ObstacleGrid.size(), N = ObstacleGrid.back().size();
    std::vector<std::vector<int>> DPTable(M, std::vector<int>(N));

    // Base case.
    for (int j = 0; j < N; j++) {
      if (ObstacleGrid[0][j] == 0) {
        DPTable[0][j] = 1;
      } else {
        // If we encounter a obstacle then the remaining grids in the first row
        // cannot be reached.
        break;
      }
    }
    // Similarly to the first column.
    for (int i = 0; i < M; i++) {
      if (ObstacleGrid[i][0] == 0) {
        DPTable[i][0] = 1;
      } else {
        break;
      }
    }

    for (int i = 1; i < M; i++) {
      for (int j = 1; j < N; j++) {
        if (ObstacleGrid[i][j] == 0) {
          DPTable[i][j] = DPTable[i - 1][j] + DPTable[i][j - 1];
        }
        // If we encounter an obstacle in grid i,j, then the count is
        // effectively reset to zero.
      }
    }
    return DPTable.back().back();
  }
};
