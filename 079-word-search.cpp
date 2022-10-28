#include "headers.hpp"

class Solution {
public:
  bool exist(std::vector<std::vector<char>> &Board, std::string Word) {
    Board_ = &Board;
    Word_ = &Word;
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board[i].size(); j++) {
        if (Board[i][j] != Word[0]) {
          continue;
        }
        Board[i][j] = '0'; // Use '0' to mark visited. Note that the marking
                           // also represents the current search state.
        // "1" represents we have used one character.
        if (backtrack_(1, {i, j})) {
          return true;
        }
        Board[i][j] = Word[0]; // Restore state.
      }
    }
    return false;
  }

private:
  bool backtrack_(int UsedStep, std::pair<int, int> LastStep) {
    if (UsedStep == Word_->size()) {
      return true;
    }

    for (auto [RowDir, ColDir] : Directions_) {
      auto NewRow = LastStep.first + RowDir;
      auto NewCol = LastStep.second + ColDir;
      if (!isValidRange(NewRow, NewCol)) {
        // NewPos is out of bound.
        continue;
      }

      // The new character we should look is, of course, at the position
      // "UsedStep" of Word_.
      // But the condition actually check two situations at the same time:
      // 1. The Word_ character and Board_ character are the same.
      // 2. The Board_ grid has NOT been visited.
      if ((*Board_)[NewRow][NewCol] != (*Word_)[UsedStep]) {
        continue;
      }

      (*Board_)[NewRow][NewCol] = '0'; // Mark Visited.
      if (backtrack_(UsedStep + 1, {NewRow, NewCol})) {
        return true;
      }
      (*Board_)[NewRow][NewCol] = (*Word_)[UsedStep]; // Restore state.
    }
    return false;
  }
  bool isValidRange(int Row, int Col) {
    return Row >= 0 && Row < Board_->size() && Col >= 0 &&
           Col < (*Board_)[0].size();
  };
  std::vector<std::vector<char>> *Board_;
  std::string const *Word_;
  const std::vector<std::pair<int, int>> Directions_{
      {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};