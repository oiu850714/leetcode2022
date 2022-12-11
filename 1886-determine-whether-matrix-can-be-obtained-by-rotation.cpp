#include "headers.hpp"

class Solution {
public:
  using MatrixTy = std::vector<std::vector<int>>;

  // Just use 048.
  bool findRotation(MatrixTy &Mat, const MatrixTy &Target) {
    return Mat == Target || (rotate_(Mat), Mat == Target) ||
           (rotate_(Mat), Mat == Target) || (rotate_(Mat), Mat == Target);
  }

private:
  // Copied from 048.
  void rotate_(MatrixTy &Matrix) {
    // The recursive structure is essentially like 054.

    int StartLayer = 0;
    int Size = Matrix.size();
    rotateRecursive_(Matrix, StartLayer, Size);
    return;
  }

  void rotateRecursive_(MatrixTy &Matrix, int StartLayer, int Size) {
    if (Size <= 1) {
      return;
    }
    // Notice that we only need to swap Size - 1 times, NOT Size times.
    for (int Idx = 0; Idx < Size - 1; Idx++) {
      int Top = StartLayer, TopIdx = StartLayer + Idx;
      int Right = StartLayer + Size - 1, RightIdx = Top + Idx;
      int Down = StartLayer + Size - 1, DownIdx = Right - Idx;
      int Left = StartLayer, LeftIdx = Down - Idx;
      // clang-format off
      std::tie(
        Matrix[Top][TopIdx],
        Matrix[RightIdx][Right],
        Matrix[Down][DownIdx],
        Matrix[LeftIdx][Left])
        = std::tuple{
            Matrix[LeftIdx][Left],
            Matrix[Top][TopIdx],
            Matrix[RightIdx][Right],
            Matrix[Down][DownIdx],
          };
      // clang-format on
    }
    rotateRecursive_(Matrix, StartLayer + 1, Size - 2);
  }
};
