#include "headers.hpp"

class Solution {
  // Similar problem: 200.
public:
  int orangesRotting(std::vector<std::vector<int>> &Grid) {
    auto Minutes = bfsFromAQueue(Grid, findRottenGrid(Grid));
    return hasFreshGrid(Grid) ? -1 : Minutes;
  }

private:
  // Ugly, but <<Row, Col>, Level>
  using FrontierElement = std::pair<std::pair<int, int>, int>;
  using FrontierType = std::queue<FrontierElement>;
  using GridType = std::vector<std::vector<int>>;
  FrontierType findRottenGrid(const GridType &Grid) {
    FrontierType Ret;
    for (auto i = 0; i < Grid.size(); i++) {
      for (auto j = 0; j < Grid[0].size(); j++) {
        if (Grid[i][j] == ROTTEN) {
          // Row i, Column j, rotten in 0-minutes.
          Ret.push({{i, j}, 0});
        }
      }
    }
    return Ret;
  }

  bool hasFreshGrid(const GridType &Grid) {
    for (const auto &Row : Grid) {
      if (std::find(Row.begin(), Row.end(), FRESH) != Row.end()) {
        return true;
      }
    }
    return false;
  }

  int bfsFromAQueue(std::vector<std::vector<int>> &Grid,
                    FrontierType Frontier) {
    auto exploreLandAndEnqueue = [&Grid, &Frontier](FrontierElement E) {
      auto [RowCol, Level] = E;
      auto [Row, Col] = RowCol;
      Grid[Row][Col] = ROTTEN;
      Frontier.push(E);
    };
    auto isValidRange = [&Grid](int Row, int Col) {
      return Row >= 0 && Row < Grid.size() && Col >= 0 && Col < Grid[0].size();
    };

    int MaxLevel = 0;
    while (!Frontier.empty()) {
      auto [RowCol, Level] = Frontier.front();
      auto [Row, Col] = RowCol;
      MaxLevel = std::max(MaxLevel, Level);
      Frontier.pop();
      // up, down, left, right
      std::vector<std::pair<int, int>> Directions{
          {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      for (auto [RowDir, ColDir] : Directions) {
        auto NewRow = Row + RowDir, NewCol = Col + ColDir;
        if (isValidRange(NewRow, NewCol) && Grid[NewRow][NewCol] == FRESH) {
          exploreLandAndEnqueue({{NewRow, NewCol}, Level + 1});
        }
      }
    }
    return MaxLevel;
  }
  static constexpr int EMPTY = 0, FRESH = 1, ROTTEN = 2;
};
