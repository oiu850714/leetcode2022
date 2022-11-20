#include "headers.hpp"

using BoardTy = std::vector<std::vector<int>>;
class Solution {
  // Use 2, 3, 4, 5 to encode the old and new states.
  // 2: Old dead, New dead.
  // 3: Old dead, New live.
  // 4: Old live, New dead.
  // 5: Old live, New live.
  // enum class is better, but overkill in this case.
  enum State {
    OldDeadNewDead = 2,
    OldDeadNewLive = 3,
    OldLiveNewDead = 4,
    OldLiveNewLive = 5,
  };

  bool isOldLive_(int Val) {
    // Val == 1 because the val has not been updated.
    return Val == 1 || Val == State::OldLiveNewDead ||
           Val == State::OldLiveNewLive;
  }
  bool isNewLive_(int Val) {
    return Val == State::OldDeadNewLive || Val == State::OldLiveNewLive;
  }

public:
  void gameOfLife(BoardTy &Board) {
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board[i].size(); j++) {
        Board[i][j] = calculate_(i, j, Board);
      }
    }
    for (int i = 0; i < Board.size(); i++) {
      for (int j = 0; j < Board[i].size(); j++) {
        Board[i][j] = isNewLive_(Board[i][j]);
      }
    }
  }

  int calculate_(int i, int j, const BoardTy &Board) {
    auto ActiveNeighbors = activeNeighbors_(i, j, Board);
    if (isOldLive_(Board[i][j])) {
      // Rule 1 to rule 3.
      return (ActiveNeighbors == 2 || ActiveNeighbors == 3)
                 ? State::OldLiveNewLive
                 : State::OldLiveNewDead;
    } else {
      // Rule 4.
      return (ActiveNeighbors == 3) ? State::OldDeadNewLive
                                    : State::OldDeadNewDead;
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
              Col < Board[0].size())         // is valid range
             && isOldLive_(Board[Row][Col]); // is active
    }
    return Ret;
  }
};
