#include "headers.hpp"

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &Grid) {
    int NumIslands = 0;
    for (size_t i = 0; i < Grid.size(); i++) {
      for (size_t j = 0; j < Grid[0].size(); j++) {
        if (Grid[i][j] == EXPLORED_LAND) {
          // explored
          continue;
        }
        if (Grid[i][j] == WATER) {
          // water
          continue;
        }
        // else, location i, j is a unexplored land
        BFS(Grid, i, j);
        NumIslands += 1;
      }
    }
    return NumIslands;
  }

private:
  void BFS(std::vector<std::vector<char>> &Grid, size_t SR, size_t SC) {
    std::queue<std::pair<int, int>> Frontier;
    auto exploreLandAndEnqueue = [&Grid, &Frontier](int Row, int Col) {
      // XXX: Hack, just use the original lvalue input to record exploration.
      Grid[Row][Col] = EXPLORED_LAND;
      Frontier.push({Row, Col});
    };
    auto isValidRange = [&Grid](int Row, int Col) {
      return Row >= 0 && Row < Grid.size() && Col >= 0 && Col < Grid[0].size();
    };
    exploreLandAndEnqueue(SR, SC);
    while (!Frontier.empty()) {
      auto [Row, Col] = Frontier.front();
      Frontier.pop();
      // up, down, left, right
      std::vector<std::pair<int, int>> Directions{
          {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      for (auto [RowDir, ColDir] : Directions) {
        auto NewRow = Row + RowDir, NewCol = Col + ColDir;
        if (isValidRange(NewRow, NewCol) && Grid[NewRow][NewCol] == LAND) {
          exploreLandAndEnqueue(NewRow, NewCol);
        }
      }
    }
  }
  static const char LAND = '1', WATER = '0', EXPLORED_LAND = 'E';
};