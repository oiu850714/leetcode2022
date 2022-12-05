#include "headers.hpp"

class Solution {
public:
  int maximalSquare(std::vector<std::vector<char>> &Matrix) {
    std::vector<std::vector<int>> DPTable(Matrix.size(),
                                          std::vector<int>(Matrix[0].size()));
    int MaxSquareSide = 0;
    // Base cases.
    for (int i = 0; i < Matrix.size(); i++) {
      DPTable[i][0] = Matrix[i][0] == '1';
      MaxSquareSide = std::max(MaxSquareSide, DPTable[i][0]);
    }
    for (int j = 0; j < Matrix[0].size(); j++) {
      DPTable[0][j] = Matrix[0][j] == '1';
      MaxSquareSide = std::max(MaxSquareSide, DPTable[0][j]);
    }

    for (int i = 1; i < Matrix.size(); i++) {
      for (int j = 1; j < Matrix[0].size(); j++) {
        DPTable[i][j] = Matrix[i][j] == '0'
                            ? 0
                            : std::min({DPTable[i - 1][j - 1],
                                        DPTable[i - 1][j], DPTable[i][j - 1]}) +
                                  1;
        MaxSquareSide = std::max(MaxSquareSide, DPTable[i][j]);
      }
    }
    return MaxSquareSide * MaxSquareSide;
  }
};
