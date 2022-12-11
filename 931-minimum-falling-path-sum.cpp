#include "headers.hpp"

class Solution {
public:
  int minFallingPathSum(std::vector<std::vector<int>> &Matrix) {
    assert(!Matrix.empty() && Matrix.size() == Matrix[0].size());
    const auto N = Matrix.size();
    auto DPRow = Matrix[0];
    for (int Row = 1; Row < N; Row++) {
      decltype(DPRow) DPNewRow(N);
      constexpr auto MAX = std::numeric_limits<int>::max();
      for (int Col = 0; Col < N; Col++) {
        auto UpLeft = Col != 0 ? DPRow[Col - 1] : MAX;
        auto Up = DPRow[Col];
        auto UpRight = Col != N - 1 ? DPRow[Col + 1] : MAX;
        DPNewRow[Col] = Matrix[Row][Col] + std::min({UpLeft, Up, UpRight});
      }
      DPRow.swap(DPNewRow);
    }
    return *std::min_element(DPRow.begin(), DPRow.end());
  }
};
