#include "headers.hpp"

class Solution {
public:
  std::string getPermutation(int N, int K) {
    // Initialization
    std::string Ret;
    for (char i = '1'; i <= N + '0'; i++) {
      Ret.push_back(i);
    }

    backtrack_(Ret, 0, 1, K);
    return Ret;
  }

private:
  constexpr int factorial_(int K) {
    return std::array<int, 10>{
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}[K];
  }

  void backtrack_(std::string &CurrStr, int CurrDigitIdx, int CurrStrOrder,
                  const int K) {
    if (CurrStrOrder == K) {
      return;
    }
    int NumsPermsWithoutCurrDigit =
        factorial_(CurrStr.size() - (CurrDigitIdx + 1));
    int RemainingOrder = K - CurrStrOrder;

    // If fact, we can skip this check:
    // If the condition is true, then the swap and sorting below leave the
    // CurrString untouched, and the calculated new order is still the same as
    // the old one.
    if (RemainingOrder < NumsPermsWithoutCurrDigit) {
      return backtrack_(CurrStr, CurrDigitIdx + 1, CurrStrOrder, K);
    }

    std::swap(
        CurrStr[CurrDigitIdx],
        CurrStr[CurrDigitIdx + RemainingOrder / NumsPermsWithoutCurrDigit]);
    std::sort(CurrStr.begin() + CurrDigitIdx + 1, CurrStr.end());
    int OrderOfModifiedStr =
        CurrStrOrder + (RemainingOrder / NumsPermsWithoutCurrDigit) *
                           NumsPermsWithoutCurrDigit;
    backtrack_(CurrStr, CurrDigitIdx + 1, OrderOfModifiedStr, K);
  }
};
