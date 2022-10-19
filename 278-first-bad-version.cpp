#include "headers.hpp"

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
  // Reference: git bisect command.
  // HACK: change input type to size_t to prevent N + 1 an overflow on int.
  int firstBadVersion(size_t N) {
    // Version representation: [beg, end)
    size_t Beg = 1, End = N + 1, MinBadVersion = N;
    while (Beg < End) { // the interval has at least one element
      auto Mid = Beg + (End - Beg) / 2;
      if (!isBadVersion(Mid)) {
        Beg = Mid + 1;
      } else {
        MinBadVersion = std::min(MinBadVersion, Mid);
        End = Mid;
      }
    }
    // After the loop, we exclude ALL possible bad versions, and store the
    // minimum in MinBadVersion.
    return static_cast<int>(MinBadVersion);
  }
};