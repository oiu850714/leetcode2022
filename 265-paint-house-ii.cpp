#include "headers.hpp"

class Solution {
public:
  int minCostII(std::vector<std::vector<int>> &Costs) {
    assert(Costs.size() && Costs[0].size() >= 2 && Costs[0].size() <= 20);
    auto DPRow = Costs[0];
    auto [MinIdx, SecondMinIdx] = getMinAnd2ndMinIdx_(DPRow);
    for (int i = 1; i < Costs.size(); i++) {
      std::vector<int> DPNewRow(DPRow.size());
      for (int k = 0; k < DPNewRow.size(); k++) {
        DPNewRow[k] =
            Costs[i][k] + (k != MinIdx ? DPRow[MinIdx] : DPRow[SecondMinIdx]);
      }
      DPRow.swap(DPNewRow);
      std::tie(MinIdx, SecondMinIdx) = getMinAnd2ndMinIdx_(DPRow);
    }
    return DPRow[MinIdx];
  }

private:
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
