#include "headers.hpp"

class Solution {
public:
  bool isRectangleOverlap(const std::vector<int> &R1,
                          const std::vector<int> &R2) {
    // This definitely needs a proof.
    // Not that simple.
    auto R1_X1 = R1[0], R1_Y1 = R1[1], R1_X2 = R1[2], R1_Y2 = R1[3];
    auto R2_X1 = R2[0], R2_Y1 = R2[1], R2_X2 = R2[2], R2_Y2 = R2[3];
    return (R1_X2 > R2_X1 && R2_X2 > R1_X1) && (R1_Y2 > R2_Y1 && R2_Y2 > R1_Y1);
  }
};
