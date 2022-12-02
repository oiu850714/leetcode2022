#include "headers.hpp"

class Solution {
public:
  int maxScoreSightseeingPair(const std::vector<int> &Values) {
    int Score = (Values[0] + 0) + (Values[1] - 1);
    int MaxI = 0;
    for (int MaxJ = 2; MaxJ < Values.size(); MaxJ++) {
      auto NewI = MaxJ - 1;
      MaxI = (Values[MaxI] + MaxI) > (Values[NewI] + NewI) ? MaxI : NewI;
      // The structure of best solution has two cases:
      // 1. j == Values.size() - 1, i.e. the rightmost index.
      //    Then i must be the index, with i < j, of the element with the best
      //    score.
      //    We need to consider the old j position as a new valid i position,
      //    hence we have the MaxI updating expression above.
      // 2. j < Values.size() - 1.
      //    Then the best solution is the solution of the subproblem Values[1,
      //    Values.size() -1), i.e. the current Score value.
      Score = std::max(Score, (Values[MaxI] + MaxI) + (Values[MaxJ] - MaxJ));
    }
    return Score;
  }
};
