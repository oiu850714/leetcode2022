#include "headers.hpp"

using BoardTy = std::vector<std::vector<int>>;
class Solution {
public:
  void gameOfLife(BoardTy &Board) {
    auto OldBoard = Board;
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board[i].size(); j++) {
        Board[i][j] = calculate_(i, j, OldBoard);
      }
    }
  }

  int calculate_(int i, int j, const BoardTy &Board) {
    auto ActiveNeighbors = activeNeighbors_(i, j, Board);
    if (Board[i][j] == 1) {
      // Rule 1 to rule 3.
      return ActiveNeighbors == 2 || ActiveNeighbors == 3;
    } else {
      // Rule 4.
      return ActiveNeighbors == 3;
    }
  }

  int activeNeighbors_(int i, int j, const BoardTy &Board) {
    std::array<std::pair<int, int>, 8> Neighbors{
        std::pair{i - 1, j - 1}, // top-left
        {i - 1, j},              // top
        {i - 1, j + 1},          // top-right
        {i, j - 1},              // left
        {i, j + 1},              // right
        {i + 1, j - 1},          // down-left
        {i + 1, j},              // down
        {i + 1, j + 1},          // down-right
    };
    int Ret = 0;
    for (auto [Row, Col] : Neighbors) {
      Ret += (Row >= 0 && Row < Board.size() && Col >= 0 &&
              Col < Board[0].size())  // is valid range
             && Board[Row][Col] == 1; // is active
    }
    return Ret;
  }
};
