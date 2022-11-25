#include "headers.hpp"

class Solution {
public:
  // The problem is essentially asking the next permutation.
  // See 031.
  int nextGreaterElement(int N) {
    auto S = std::to_string(N);
    auto NextGreater = S;
    if (!std::next_permutation(NextGreater.begin(), NextGreater.end())) {
      return -1;
    }
    auto NextLongLong = std::stoll(NextGreater);
    if (NextLongLong > std::numeric_limits<int>::max()) {
      return -1;
    }
    return NextLongLong;
  }
};
