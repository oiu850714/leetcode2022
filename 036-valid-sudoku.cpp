#include "headers.hpp"

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &Board) {
    for (int Row = 0; Row < 9; Row++) {
      for (int Col = 0; Col < 9; Col++) {
        if (Board[Row][Col] == '.') {
          continue;
        }

        auto Num = Board[Row][Col];
        // Check row.
        for (int j = 0; j < 9; j++) {
          if (j != Col && Board[Row][j] == Num) {
            return false;
          }
        }
        // Check column.
        for (int i = 0; i < 9; i++) {
          if (i != Row && Board[i][Col] == Num) {
            return false;
          }
        }

        // Check block
        auto BlockRow = Row / 3, BlockCol = Col / 3;
        for (int i = BlockRow * 3; i < BlockRow * 3 + 3; i++) {
          for (int j = BlockCol * 3; j < BlockCol * 3 + 3; j++) {
            if (i != Row && j != Col && Board[i][j] == Num) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};