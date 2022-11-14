#include "headers.hpp"

using MatrixTy = std::vector<std::vector<int>>;
using CoordsReturnTy = std::vector<std::vector<int>>;
using CoordsTy = std::vector<std::pair<int, int>>;

class Solution {
public:
  CoordsReturnTy spiralMatrixIII(int Rows, int Cols, int RowStart,
                                 int ColStart) {
    int RemainingGrids = Rows * Cols;
    Rows_ = Rows;
    Cols_ = Cols;
    CoordsReturnTy Coords;
    Coords.push_back({RowStart, ColStart});
    RemainingGrids -= 1;

    const std::vector<std::pair<int, int>> Directions{
        {1, 0},  // Down
        {0, -1}, // Left
        {-1, 0}, // Up
        {0, 1}   // Right
    };

    const std::vector<std::pair<int, int>> TurnDirections{
        {0, -1}, // Left
        {-1, 0}, // Up
        {0, 1},  // Right
        {0, 1}   // Right. Yes, Right. This makes us stand at the first grid of
                 // the next iteration.
    };

    // Imagine we explore on a bigger (square) matrix, and the input matrix is
    // "A PORTION" of this matrix.
    int CurrRow = RowStart, CurrCol = ColStart + 1;
    for (int Iterations = 1; RemainingGrids > 0; Iterations++) {
      for (int DirIdx = 0; DirIdx < 4; DirIdx++) {
        auto [RowDir, ColDir] = Directions[DirIdx];
        int RemainingGridsForThisDir = 2 * Iterations;
        while (RemainingGridsForThisDir > 0) {
          if (isValidRange_(CurrRow, CurrCol)) {
            Coords.push_back({CurrRow, CurrCol});
            RemainingGrids--;
            if (RemainingGrids == 0) {
              return Coords;
            }
          }
          RemainingGridsForThisDir--;
          if (RemainingGridsForThisDir > 0) {
            // We do not stand at the "last grid" for this direction, so we can
            // take a step forward.
            CurrRow += RowDir;
            CurrCol += ColDir;
          }
        }

        // Turn direction.
        auto [RowTurnDir, ColTurnDir] = TurnDirections[DirIdx];
        CurrRow += RowTurnDir;
        CurrCol += ColTurnDir;
      }
    }
    return Coords;
  }

  int Rows_;
  int Cols_;
  bool isValidRange_(int Row, int Col) {
    return Row >= 0 && Row < Rows_ && Col >= 0 && Col < Cols_;
  };
};
