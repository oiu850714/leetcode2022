#include "headers.hpp"

using BoardTy = std::vector<std::vector<int>>;
class Solution {
public:
  // Note that we can also use -1 to mark visited grids.
  int uniquePathsIII(BoardTy &Board) {
    auto [BegRow, BegCol] = getStartPos_(Board);

    auto NumNonObstableGrids = getNumNonObstacles_(Board);
    // All grids, minus obstacles, minus the ending square.
    auto RemainingGrids =
        Board.size() * Board.back().size() - NumNonObstableGrids - 1;
    backtrack_(BegRow, BegCol, RemainingGrids, Board);
    return Result_;
  }

private:
  int Result_ = 0;

  int getNumNonObstacles_(const BoardTy &Board) {
    int Ret = 0;
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board.back().size(); j++) {
        if (Board[i][j] == -1) {
          Ret += 1;
        }
      }
    }
    return Ret;
  }

  std::pair<int, int> getStartPos_(const BoardTy &Board) {
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board.back().size(); j++) {
        if (Board[i][j] == 1) {
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }

  void backtrack_(int Row, int Col, int RemainingGrids, BoardTy &Board) {
    if (Board[Row][Col] == 2) {
      // The path actually uses all available grids.
      if (RemainingGrids == 0) {
        Result_ += 1;
      }
      return;
    }

    // Encounter an obstacle.
    if (Board[Row][Col] == -1) {
      return;
    }

    auto OldVal = Board[Row][Col];
    Board[Row][Col] = -1;
    std::array<std::pair<int, int>, 4> Directions_{
        std::pair{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto [RowDir, ColDir] : Directions_) {
      auto NewRow = Row + RowDir, NewCol = Col + ColDir;
      if (NewRow >= 0 && NewRow < Board.size() && NewCol >= 0 &&
          NewCol < Board.back().size()) {
        backtrack_(NewRow, NewCol, RemainingGrids - 1, Board);
      }
    }
    Board[Row][Col] = OldVal;
    return;
  }
};
