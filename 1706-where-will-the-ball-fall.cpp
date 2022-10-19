#include "headers.hpp"

class Solution {
public:
  std::vector<int> findBall(std::vector<std::vector<int>> &Grid) {
    const auto NumBall = Grid[0].size();
    std::vector<int> Ret(NumBall);

    // Just simulate each ball.
    for (int j = 0; j < NumBall; j++) {
      int BallCol = j;
      int BallNextRow = 0;
      bool IsBlocked = false;
      while (BallNextRow < Grid.size()) {
        if (Grid[BallNextRow][BallCol] == 1) {
          if (BallCol + 1 >= Grid[0].size()) {
            // The bottomright entry is a wall.
            IsBlocked = true;
            break;
          } else if (Grid[BallNextRow][BallCol + 1] == -1) {
            // Encounter a "V" shaped path.
            IsBlocked = true;
            break;
          } else {
            BallNextRow++;
            BallCol++;
          }
        } else {
          if (BallCol == 0) {
            // The bottomleft entry is a wall.
            IsBlocked = true;
            break;
          } else if (Grid[BallNextRow][BallCol - 1] == 1) {
            // Encounter a "V" shaped path.
            IsBlocked = true;
            break;
          } else {
            BallNextRow++;
            BallCol--;
          }
        }
      }
      Ret[j] = IsBlocked ? -1 : BallCol;
    }
    return Ret;
  }
};