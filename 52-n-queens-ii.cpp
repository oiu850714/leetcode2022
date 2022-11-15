#include "headers.hpp"

using PosTy = std::pair<int, int>;
using QueensPosTy = std::vector<PosTy>;

// Essentially the same as 051.
class Solution {
public:
  int totalNQueens(int N) {
    N_ = N;
    int Ret = 0;
    for (int i = 0; i < N; i++) {
      QueensPosTy QueensPos{{0, i}};
      Ret += backtrack_(QueensPos);
    }
    return Ret;
  }

private:
  int N_;

  int backtrack_(QueensPosTy &QueensPos) {
    if (QueensPos.size() == N_) {
      return 1;
    }

    int Ret = 0;
    // Always put new queen at the new row.
    int NewRow = QueensPos.size();
    for (int NewCol = 0; NewCol < N_; NewCol++) {
      if (isSafeToAdd_(QueensPos, {NewRow, NewCol})) {
        QueensPos.push_back({NewRow, NewCol});
        Ret += backtrack_(QueensPos);
        QueensPos.pop_back();
      }
    }

    return Ret;
  }

  // Same as 051.
  bool isSafeToAdd_(const QueensPosTy &QueensPos, const PosTy &NewPos) {
    for (const auto &QueenPos : QueensPos) {
      if (QueenPos.second == NewPos.second) {
        return false;
      }

      if (std::abs(QueenPos.first - NewPos.first) ==
          std::abs(QueenPos.second - NewPos.second)) {
        return false;
      }
    }
    return true;
  }
};
