#include "headers.hpp"

class Solution {
public:
  int minFallingPathSum(std::vector<std::vector<int>> &Matrix) {
    auto DPRow = Matrix[0];
    for (int Row = 1; Row < Matrix.size(); Row++) {
      std::vector<int> NewRow(DPRow.size());
      for (int Col = 0; Col < Matrix.size(); Col++) {
        auto UpLeft = 0, Up = 0, UpRight = 0;
        if (Col == 0) {
          UpLeft = std::numeric_limits<int>::max();
          Up = DPRow[Col];
          UpRight = DPRow[Col + 1];
        } else if (Col == Matrix.size() - 1) {
          UpLeft = DPRow[Col - 1];
          Up = DPRow[Col];
          UpRight = std::numeric_limits<int>::max();
        } else {
          UpLeft = DPRow[Col - 1];
          Up = DPRow[Col];
          UpRight = DPRow[Col + 1];
        }
        NewRow[Col] = Matrix[Row][Col] + std::min({UpLeft, Up, UpRight});
      }
      DPRow.swap(NewRow);
    }
    return *std::min_element(DPRow.begin(), DPRow.end());
  }
};
