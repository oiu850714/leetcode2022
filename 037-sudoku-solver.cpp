#include "headers.hpp"

using BoardTy = std::vector<std::vector<char>>;

class Solution {
public:
  // By assumption, input must have one and only one solution.
  void solveSudoku(BoardTy &Board) {
    Board_ = &Board;
    backtrack_(0, 0);
  }

private:
  BoardTy *Board_;

  bool backtrack_(int Row, int Col) {
    if (Row == 9 && Col == 0) {
      // All grids have been filled.
      return true;
    }

    auto [NextRow, NextCol] = getNextIndex_(Row, Col);
    if ((*Board_)[Row][Col] != '.') {
      // Current grid has been filled, return the result of the recursion with
      // the index of next grid.
      return backtrack_(NextRow, NextCol);
    }
    for (int Num = 1; Num <= 9; Num++) {
      if (!isValidToFill_(Num, Row, Col)) {
        continue;
      }
      (*Board_)[Row][Col] = Num + '0';
      if (!backtrack_(NextRow, NextCol)) {
        (*Board_)[Row][Col] = '.'; // Restore state.
        continue;
      }
      return true;
    }
    return false; // This only happens when the input is not solvable.
  }

  std::pair<int, int> getNextIndex_(int Row, int Col) {
    return {(Col == 8 ? Row + 1 : Row), (Col + 1) % 9};
  }

  bool isValidToFill_(int Num, int Row, int Col) {
    // Check row.
    for (int j = 0; j < 9; j++) {
      if ((*Board_)[Row][j] == Num + '0') {
        return false;
      }
    }
    // Check column.
    for (int i = 0; i < 9; i++) {
      if ((*Board_)[i][Col] == Num + '0') {
        return false;
      }
    }

    // Check block
    auto BlockRow = Row / 3, BlockCol = Col / 3;
    for (int i = BlockRow * 3; i < BlockRow * 3 + 3; i++) {
      for (int j = BlockCol * 3; j < BlockCol * 3 + 3; j++) {
        if ((*Board_)[i][j] == Num + '0') {
          return false;
        }
      }
    }
    return true;
  }
};