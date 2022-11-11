#include "headers.hpp"

class Solution {
public:
  std::string convert(std::string S, const size_t Row) {
    if (Row == 1) {
      // S "degenerates" to a normal string.
      return S;
    }
    std::string Ret;
    const auto GroupSize = 2 * Row - 2;
    // 0th row.
    for (size_t i = 0; i < S.size(); i += GroupSize) {
      Ret.push_back(S[i]);
    }

    // 1st ~ Row-2-th row.
    // P     I    N
    //^A   L S  I G   (Index = R)
    // Y A   H R
    // P     I
    // -----------------
    // P     I    N
    // A  ^L S  I G   (Index += 2 * (Row - R) - 1 - 1)
    // Y A   H R
    // P     I
    // ----------------
    // P     I    N
    // A   L^S  I G   (Index += 2 * R)
    // Y A   H R
    // P     I
    // ----------------
    for (size_t R = 1; R < Row - 1; R++) {
      for (size_t i = R; i < S.size();) {
        Ret.push_back(S[i]);
        i += 2 * (Row - R) - 1 - 1;

        if (i < S.size()) {
          Ret.push_back(S[i]);
          i += 2 * R;
        }
      }
    }

    // Row-1-th row.
    for (size_t i = Row - 1; i < S.size(); i += GroupSize) {
      Ret.push_back(S[i]);
    }
    return Ret;
  }
};
