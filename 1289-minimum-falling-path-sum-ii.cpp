#include "headers.hpp"

class Solution {
public:
  int minFallingPathSum(const std::vector<std::vector<int>> &Grid) {
    if (Grid.size() == 1) {
      return Grid[0][0];
    }
    auto DPRow = Grid[0];
    auto [MinIdx, SecondMinIdx] = getMinAnd2ndMinIdx_(DPRow);
    for (int Row = 1; Row < Grid.size(); Row++) {
      std::vector<int> NewDPRow(DPRow.size());
      for (int Col = 0; Col < DPRow.size(); Col++) {
        if (Col == MinIdx) {
          NewDPRow[Col] = Grid[Row][Col] + DPRow[SecondMinIdx];
        } else {
          NewDPRow[Col] = Grid[Row][Col] + DPRow[MinIdx];
        }
      }
      DPRow.swap(NewDPRow);
      std::tie(MinIdx, SecondMinIdx) = getMinAnd2ndMinIdx_(DPRow);
    }
    return DPRow[MinIdx];
  }

private:
  // Copied from 265.
  std::pair<int, int> getMinAnd2ndMinIdx_(const std::vector<int> &DPRow) {
    assert(DPRow.size() >= 2);
    int MinIdx = (DPRow[0] < DPRow[1] ? 0 : 1);
    int SecondMinIdx = (DPRow[0] < DPRow[1] ? 1 : 0);
    for (int i = 2; i < DPRow.size(); i++) {
      if (DPRow[i] < DPRow[MinIdx]) {
        std::tie(MinIdx, SecondMinIdx) = std::pair{i, MinIdx};
      } else if (DPRow[i] < DPRow[SecondMinIdx]) {
        SecondMinIdx = i;
      }
    }
    return {MinIdx, SecondMinIdx};
  }
};
