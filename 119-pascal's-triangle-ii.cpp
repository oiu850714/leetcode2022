#include "headers.hpp"

class Solution {
public:
  std::vector<int> getRow(int RowIdx) {
    // Just some base cases.
    if (RowIdx == 0) {
      return {1};
    }
    if (RowIdx == 1) {
      return {1, 1};
    }

    std::vector<int> LastRow{1, 1};
    for (int CurrRow = 2; CurrRow <= RowIdx; CurrRow++) {
      std::vector<int> NewRow{1};
      auto LastRowLen = CurrRow; // Nasty, but true.
      for (size_t LastRowIdx = 0; LastRowIdx < LastRowLen - 1; LastRowIdx++) {
        NewRow.push_back(LastRow[LastRowIdx] + LastRow[LastRowIdx + 1]);
      }
      NewRow.push_back(1);
      LastRow = std::move(NewRow);
    }
    return LastRow;
  }
};