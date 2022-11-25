#include "headers.hpp"

class Solution {
  using BoardTy = std::vector<std::vector<int>>;

public:
  BoardTy updateMatrix(BoardTy &Board) {
    // Use -1 to mark visited.
    std::vector<std::pair<int, int>> Queue;
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board.back().size(); j++) {
        if (Board[i][j] == 0) {
          Queue.push_back({i, j});
          Board[i][j] = -1;
        }
      }
    }

    BoardTy Ret(Board.size(), std::vector<int>(Board.back().size()));
    int Level = 1;
    while (!Queue.empty()) {
      decltype(Queue) NextQueue;
      for (auto [Row, Col] : Queue) {
        auto isValidRange_ = [&Board](int Row, int Col) {
          return Row >= 0 && Row < Board.size() && Col >= 0 &&
                 Col < Board[0].size();
        };
        std::vector<std::pair<int, int>> Directions{
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [RowDir, ColDir] : Directions) {
          auto NewRow = Row + RowDir, NewCol = Col + ColDir;
          if (isValidRange_(NewRow, NewCol) && Board[NewRow][NewCol] != -1) {
            Board[NewRow][NewCol] = -1;
            Ret[NewRow][NewCol] = Level;
            NextQueue.push_back({NewRow, NewCol});
          }
        }
      }
      Queue.swap(NextQueue);
      Level += 1;
    }
    return Ret;
  }
};
