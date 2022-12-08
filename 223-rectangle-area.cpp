#include "headers.hpp"

class Solution {
public:
  int computeArea(int Ax1, int Ay1, int Ax2, int Ay2, int Bx1, int By1, int Bx2,
                  int By2) {
    int AreaA = (Ax2 - Ax1) * (Ay2 - Ay1);
    int AreaB = (Bx2 - Bx1) * (By2 - By1);
    if (!isRectangleOverlap_({Ax1, Ay1, Ax2, Ay2}, {Bx1, By1, Bx2, By2})) {
      return AreaA + AreaB;
    }

    return AreaA + AreaB -
           overlapping_({Ax1, Ay1, Ax2, Ay2}, {Bx1, By1, Bx2, By2});
  }

  // Copied from 836.
  bool isRectangleOverlap_(const std::vector<int> &R1,
                           const std::vector<int> &R2) {
    // This definitely needs a proof.
    // Not that simple.
    auto R1_X1 = R1[0], R1_Y1 = R1[1], R1_X2 = R1[2], R1_Y2 = R1[3];
    auto R2_X1 = R2[0], R2_Y1 = R2[1], R2_X2 = R2[2], R2_Y2 = R2[3];
    return (R1_X2 > R2_X1 && R2_X2 > R1_X1) && (R1_Y2 > R2_Y1 && R2_Y2 > R1_Y1);
  }

  // Assert isRectangleOverlap_(R1, R2).
  int overlapping_(const std::vector<int> &R1, const std::vector<int> &R2) {
    auto R1_X1 = R1[0], R1_Y1 = R1[1], R1_X2 = R1[2], R1_Y2 = R1[3];
    auto R2_X1 = R2[0], R2_Y1 = R2[1], R2_X2 = R2[2], R2_Y2 = R2[3];
    // For the four options, the first two are to compute the "normal"
    // overlapping; the last two are that the overlapping cannot be greater
    // than the (x- or y-) sides of the two rectangles.
    return std::min(
               {R1_X2 - R2_X1, R2_X2 - R1_X1, R1_X2 - R1_X1, R2_X2 - R2_X1}) *
           std::min(
               {R1_Y2 - R2_Y1, R2_Y2 - R1_Y1, R1_Y2 - R1_Y1, R2_Y2 - R2_Y1});
  }
};
