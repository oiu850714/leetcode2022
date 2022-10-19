#include "headers.hpp"

class Solution {
public:
  std::vector<int> spiralOrder(const std::vector<std::vector<int>> &Matrix) {
    std::vector<int> Ret;
    int StartRow = 0, StartCol = 0;
    int Width = Matrix[0].size(), Height = Matrix.size();
    spiralRecursive(Matrix, StartRow, StartCol, Height, Width, Ret);
    return Ret;
  }
  void spiralRecursive(const std::vector<std::vector<int>> &Matrix,
                       const int StartRow, const int StartCol, const int Height,
                       const int Width, std::vector<int> &Ret) {
    if (Height == 0 || Width == 0) {
      // The spiral degenerates to be empty.
      return;
    }
    if (Height == 1) {
      // The spiral degenerates to be an 1 X n matrix.
      for (int Col = StartCol; Col < StartCol + Width; Col++) {
        Ret.push_back(Matrix[StartRow][Col]);
      }
      return;
    }
    if (Width == 1) {
      // The spiral degenerates to be an m X 1 matrix.
      for (int Row = StartRow; Row < StartRow + Height; Row++) {
        Ret.push_back(Matrix[Row][StartCol]);
      }
      return;
    }
    // Both the width and the height of the spiral are at least two, so we can
    // traverse the spiral using the "right, down, left, up" order.
    auto CurrRow = StartRow, CurrCol = StartCol;
    auto RowDir = 0, ColDir = 1;
    // Directions:
    //     Right: (0, 1),
    //     Down: (1, 0),
    //     Left: (0, -1),
    //     Up: (-1, 0),
    do {
      Ret.push_back(Matrix[CurrRow][CurrCol]);
      // Notice the boundary check condition; the condition makes the CurrCol
      // and CurrRow always valid until it again becomes StartRow and StartCol.
      if (RowDir == 0 && ColDir == 1) {
        if (CurrCol < StartCol + Width - 1) {
          CurrCol++;
        } else {
          CurrRow++;
          RowDir = 1, ColDir = 0;
        }
      } else if (RowDir == 1 && ColDir == 0) {
        if (CurrRow < StartRow + Height - 1) {
          CurrRow++;
        } else {
          CurrCol--;
          RowDir = 0, ColDir = -1;
        }
      } else if (RowDir == 0 && ColDir == -1) {
        if (CurrCol > StartCol) {
          CurrCol--;
        } else {
          CurrRow--;
          RowDir = -1, ColDir = 0;
        }
      } else if (RowDir == -1 && ColDir == 0) {
        if (CurrRow > StartRow) {
          CurrRow--;
        }
      }
    } while (CurrRow != StartRow || CurrCol != StartCol);
    spiralRecursive(Matrix, StartRow + 1, StartCol + 1, Height - 2, Width - 2,
                    Ret);
  }
};