#include "headers.hpp"

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &Matrix, int Target) {
    // Assume the Matrix has at least one row and one column.
    int NumElements = Matrix.size() * Matrix[0].size();
    // The point is that always treat the Matrix as 1D array, except when
    // indexing it.

    // Modified from 704. The range representation is half-closed: [Beg, End).
    auto Beg = 0, End = NumElements;
    while (End - Beg >= 1) {
      auto Mid = Beg + (End - Beg) / 2;
      auto [Row, Col] = convertIndex(Mid, Matrix);
      if (Matrix[Row][Col] == Target) {
        return true;
      }
      if (Matrix[Row][Col] < Target) {
        Beg = Mid + 1;
      } else {
        End = Mid;
      }
    }
    return false;
  }

  std::pair<int, int>
  convertIndex(int Index, const std::vector<std::vector<int>> &Matrix) {
    // Assume Matrix and Index are valid.
    return {Index / Matrix[0].size(), Index % Matrix[0].size()};
  }
};