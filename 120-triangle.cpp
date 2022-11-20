#include "headers.hpp"

class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> &Triangle) {
    auto DPRow = Triangle.back();

    // Notice some offset by 1 calculations;
    // e.g. The i-th row really has i + 1 elements.
    for (int RowIdx = Triangle.size() - 2; RowIdx >= 0; RowIdx--) {
      auto NumElementsOfRow = RowIdx + 1;
      std::vector<int> DPNewRow(NumElementsOfRow);
      for (int ColIdx = 0; ColIdx <= RowIdx; ColIdx++) {
        DPNewRow[ColIdx] = std::min(DPRow[ColIdx], DPRow[ColIdx + 1]) +
                           Triangle[RowIdx][ColIdx];
      }
      DPRow.swap(DPNewRow);
    }
    return DPRow.front();
  }
};
