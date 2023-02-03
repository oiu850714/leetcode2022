#include "headers.hpp"

class Solution {
public:
  bool searchMatrix(const std::vector<std::vector<int>> &Matrix, int Target) {
    int Row = Matrix.size() - 1, Col = 0;
    while (Row >= 0 && Col < Matrix.back().size()) {
      if (Matrix[Row][Col] == Target) {
        return true;
      } else if (Matrix[Row][Col] > Target) {
        --Row;
      } else {
        ++Col;
      }
    }
    return false;
  }
};
