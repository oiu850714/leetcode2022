#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> generate(int NumRows) {
    // Just some base cases.
    if (NumRows == 1) {
      return {{1}};
    }
    if (NumRows == 2) {
      return {{1}, {1, 1}};
    }

    std::vector<std::vector<int>> Ret;
    Ret.push_back({1});
    Ret.push_back({1, 1});
    for (int CurrRow = 2; CurrRow < NumRows; CurrRow++) {
      std::vector<int> NewRow{1};
      auto LastRowLen = CurrRow; // Nasty, but true.
      for (size_t LastRowIdx = 0; LastRowIdx < LastRowLen - 1; LastRowIdx++) {
        NewRow.push_back(Ret.back()[LastRowIdx] + Ret.back()[LastRowIdx + 1]);
      }
      NewRow.push_back(1);
      Ret.push_back(std::move(NewRow));
    }
    return Ret;
  }
};