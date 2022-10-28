#include "headers.hpp"

using PosTy = std::pair<int, int>;
using BoardsTy = std::vector<std::string>;
using AnswersTy = std::vector<BoardsTy>;
using QueensPosTy = std::vector<PosTy>;

class Solution {
public:
  AnswersTy solveNQueens(int N) {
    N_ = N;
    for (int i = 0; i < N; i++) {
      QueensPosTy QueensPos{{0, i}};
      backtrack_(QueensPos);
    }
    return std::move(Answers_);
  }

private:
  AnswersTy Answers_;
  int N_;

  void backtrack_(QueensPosTy &QueensPos) {
    if (QueensPos.size() == N_) {
      Answers_.push_back(convertToBoard_(QueensPos));
      return;
    }

    // Always put new queen at the new row.
    int NewRow = QueensPos.size();
    for (int NewCol = 0; NewCol < N_; NewCol++) {
      if (isSafeToAdd_(QueensPos, {NewRow, NewCol})) {
        QueensPos.push_back({NewRow, NewCol});
        backtrack_(QueensPos);
        QueensPos.pop_back();
      }
    }
  }

  BoardsTy convertToBoard_(const QueensPosTy &QueensPos) {
    BoardsTy Ret;
    for (const auto &QueenPos : QueensPos) {
      std::string Row;
      for (int i = 0; i < N_; i++) {
        if (i == QueenPos.second) {
          Row.push_back('Q');
        } else {
          Row.push_back('.');
        }
      }
      Ret.push_back(Row);
    }
    return Ret;
  }

  // Assume:
  // 1. All Queens in QueensPos are already safe.
  // 2. The row of NewPos is different from each Queen in QueensPos.
  // So we just check whether any off them will attack the new Queen at NewPos.
  bool isSafeToAdd_(const QueensPosTy &QueensPos, const PosTy &NewPos) {
    for (const auto &QueenPos : QueensPos) {
      // No need to check whether NewPos has the same row as old Queens.
      if (QueenPos.second == NewPos.second) {
        // Same column.
        return false;
      }

      if (std::abs(QueenPos.first - NewPos.first) ==
          std::abs(QueenPos.second - NewPos.second)) {
        // NewPos is at one of the four diagonals of old Queen.
        return false;
      }
    }
    return true;
  }
};