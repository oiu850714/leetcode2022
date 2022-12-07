#include "headers.hpp"

class Solution {
public:
  int numDecodings(std::string S) {
    assert(!S.empty());
    constexpr int Mod = 1000000007;

    // PrevTwo and Prev store the num of ways to decode S - 2 and S - 1
    // substrings, respectively.
    // Base case:
    //   0. empty encoded string has 1 way to decode.
    //   1. 1-digit encoded string has:
    //     a. 1 way to decode if it's a digit.
    //     b. 9 ways to decode if it is *.
    int64_t PrevTwo = 1, Prev = S[0] == '0' ? 0 : S[0] != '*' ? 1 : 9;
    for (int i = 1; i < S.size(); i++) {
      int64_t Curr = 0;
      const auto LastDigit = S.substr(i, 1);
      const auto LastTwoDigits = S.substr(i - 1, 2);
      if (isValidEncoding_(LastDigit)) {
        Curr += Prev * numEncodings_(LastDigit);
      }
      if (isValidEncoding_(LastTwoDigits)) {
        Curr += PrevTwo * numEncodings_(LastTwoDigits);
      }
      Curr %= Mod;
      std::tie(Prev, PrevTwo) = std::pair{Curr, Prev};
    }
    return Prev;
  }

private:
  bool isValidEncoding_(const std::string &Str) {
    if (Str.size() == 1) {
      return Str == "*" || "1" <= Str && Str <= "9";
    }
    if (Str.size() == 2) {
      return Str == "**" || Str == "1*" || Str == "2*" ||
             "*0" <= Str && Str <= "*9" || "10" <= Str && Str <= "26";
    }
    return false;
  }

  // Assert isValidEncoding_(Str).
  int numEncodings_(const std::string &Str) {
    if (Str.find("*") == std::string::npos) {
      return 1;
    }
    if (Str.size() == 1) {
      // Then Str == "*"
      return 9;
    }
    if (Str == "1*") {
      // 11, 12, ..., 19
      // Note that * can NOT be viewed as 0 by the rule of the problem.
      return 9;
    }
    if (Str == "2*") {
      // 21, 22, ..., 26
      return 6;
    }

    if (Str == "**") {
      // 1* + 2*.
      return 15;
    }

    // The remaning cases is Str == *0, *1, *2, ..., *9.
    // Then for *0 to *6, * can be replaced with 1 or 2;
    // for *7 to *9, * can only be replaced with 1.
    return Str[1] <= '6' ? 2 : 1;
  }
};
