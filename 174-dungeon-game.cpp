#include "headers.hpp"

class Solution {
public:
  int calculateMinimumHP(std::vector<std::vector<int>> &Dungeon) {
    // Assume the health point is zero at the beginning and can be negative;
    // the table stores the lowest possible health point when we visit the
    // "best" path from i, j to the bottom right with starting health point 0.
    std::vector<std::vector<int>> DPTable(Dungeon.size(),
                                          std::vector<int>(Dungeon[0].size()));

    // Base case: when the knight just start at the last grid.
    DPTable.back().back() = std::min(0, Dungeon.back().back());

    // Base case: last row without last entry.
    {
      for (int j = Dungeon.back().size() - 2; j >= 0; j--) {
        auto LowestHOfRight = DPTable.back()[j + 1];
        auto LowestHOfCurr = std::min(0, Dungeon.back()[j] + LowestHOfRight);
        DPTable.back()[j] = LowestHOfCurr;
      }
    }

    // Base case: last column with last entry.
    {
      for (int i = Dungeon.size() - 2; i >= 0; i--) {
        auto LowestHOfBottom = DPTable[i + 1].back();
        auto LowestHOfCurr = std::min(0, Dungeon[i].back() + LowestHOfBottom);
        DPTable[i].back() = LowestHOfCurr;
      }
    }

    for (int i = Dungeon.size() - 2; i >= 0; i--) {
      for (int j = Dungeon[0].size() - 2; j >= 0; j--) {
        auto BestLowestHOfSubpath =
            std::max(DPTable[i + 1][j], DPTable[i][j + 1]);
        auto LowestHOfCurr = std::min(0, Dungeon[i][j] + BestLowestHOfSubpath);
        DPTable[i][j] = LowestHOfCurr;
      }
    }
    return (DPTable[0][0] == 0 ? 1 : DPTable[0][0] * -1 + 1);
  }
};
