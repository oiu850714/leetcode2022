#include "headers.hpp"

using BoardTy = std::vector<std::vector<char>>;
using VisitedTy = std::vector<std::vector<bool>>;
using CapturedCellsTy = std::vector<std::pair<int, int>>;
using QueueTy = std::vector<std::pair<int, int>>;

class Solution {
public:
  void solve(BoardTy &Board) {
    int M = Board.size(), N = Board.back().size();
    VisitedTy Visited(M, std::vector<bool>(N));
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (Board[i][j] == 'X' || Visited[i][j]) {
          continue;
        }
        bfs_(i, j, Visited, Board);
      }
    }
  }
  void bfs_(int StartRow, int StartCol, VisitedTy &Visited, BoardTy &Board) {
    bool CannotCapture = false;
    CapturedCellsTy CapturedCells;
    QueueTy OldQueue, NewQueue;
    OldQueue.push_back({StartRow, StartCol});
    CapturedCells.push_back({StartRow, StartCol});
    Visited[StartRow][StartCol] = true;
    while (!OldQueue.empty()) {
      for (auto [OldRow, OldCol] : OldQueue) {
        for (auto [RowDir, ColDir] : std::vector<std::pair<int, int>>{
                 {-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
          auto NewRow = OldRow + RowDir, NewCol = OldCol + ColDir;
          if (!isValidRange_(NewRow, NewCol, Board)) {
            CannotCapture = true;
            continue;
          }
          if (Board[NewRow][NewCol] == 'X' || Visited[NewRow][NewCol]) {
            continue;
          }
          NewQueue.push_back({NewRow, NewCol});
          CapturedCells.push_back({NewRow, NewCol});
          Visited[NewRow][NewCol] = true;
        }
      }
      OldQueue = std::move(NewQueue);
    }
    if (!CannotCapture) {
      for (auto [CellRow, CellCol] : CapturedCells) {
        Board[CellRow][CellCol] = 'X';
      }
    }
  }

  bool isValidRange_(int Row, int Col, const BoardTy &Board) {
    return Row >= 0 && Row < Board.size() && Col >= 0 && Col < Board[0].size();
  }
};
