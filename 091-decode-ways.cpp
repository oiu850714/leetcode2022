#include "headers.hpp"

class Solution {
public:
  int numDecodings(std::string S) {
    assert(!S.empty());

    // PrevTwo and Prev store the num of ways to decode S - 2 and S - 1
    // substrings, respectively.
    // Base case:
    //   0. empty encoded string has 1 way to decode.
    //   1. 1-digit encoded string has 1 way to decode if and only if that digit
    //   is not 0.
    int PrevTwo = 1, Prev = S[0] != '0';
    for (int i = 1; i < S.size(); i++) {
      int Curr = 0;
      const auto PrevDigit = S.substr(i, 1);
      const auto PrevTwoDigits = S.substr(i - 1, 2);
      if (isValidEncoding_(PrevDigit)) {
        Curr += Prev;
      }
      if (isValidEncoding_(PrevTwoDigits)) {
        Curr += PrevTwo;
      }
      std::tie(Prev, PrevTwo) = std::pair{Curr, Prev};
    }
    return Prev;
  }

private:
  bool isValidEncoding_(const std::string &Str) {
    if (Str.size() == 1) {
      return "1" <= Str && Str <= "9";
    }
    if (Str.size() == 2) {
      return "10" <= Str && Str <= "26";
    }
    return false;
  }
};
