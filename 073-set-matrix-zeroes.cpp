#include "headers.hpp"

class Solution {
  using MatrixTy = std::vector<std::vector<int>>;

public:
  void setZeroes(MatrixTy &Matrix) {
    // 1. Record whether the first row and col need to be set to 0.
    bool FirstColGG = false, FirstRowGG = false;
    for (int i = 0; i < Matrix.size(); i++) {
      if (Matrix[i][0] == 0) {
        FirstColGG = true;
      }
    }
    for (int j = 0; j < Matrix[0].size(); j++) {
      if (Matrix[0][j] == 0) {
        FirstRowGG = true;
      }
    }

    // 2. Now, treat 0-th row and 0-th col as the hash set in the O(m + n)
    // solution. A chaotic evil technique.
    for (int i = 0; i < Matrix.size(); i++) {
      for (int j = 0; j < Matrix[0].size(); j++) {
        if (Matrix[i][j] == 0) {
          Matrix[i][0] = 0;
          Matrix[0][j] = 0;
        }
      }
    }

    // 3. Use "has set" to set the matrix elements to 0, except the first row
    // and col.
    for (int i = 1; i < Matrix.size(); i++) {
      for (int j = 1; j < Matrix[0].size(); j++) {
        if (Matrix[i][0] == 0 || Matrix[0][j] == 0) {
          Matrix[i][j] = 0;
        }
      }
    }

    // Finally, mark the first row and column as 0s, if needed.
    if (FirstRowGG) {
      Matrix[0] = std::vector<int>(Matrix[0].size());
    }
    if (FirstColGG) {
      for (int i = 0; i < Matrix.size(); i++) {
        Matrix[i][0] = 0;
      }
    }
  }
};
