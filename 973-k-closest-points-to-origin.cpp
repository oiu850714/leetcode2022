#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &Points,
                                         int K) {
    std::sort(Points.begin(), Points.end(), [](auto &&P1, auto &&P2) {
      return P1[0] * P1[0] + P1[1] * P1[1] < P2[0] * P2[0] + P2[1] * P2[1];
    });

    return std::vector(Points.begin(), Points.begin() + K);
  }
};
