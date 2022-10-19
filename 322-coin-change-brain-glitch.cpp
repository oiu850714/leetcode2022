#include "headers.hpp"

// This is a suboptimal I initially came up with.
// The dimension of DP table is accidentally one more than the better solution.
class Solution {
public:
  int coinChange(std::vector<int> &Coins, const int Amount) {
    std::vector<std::vector<int>> DPTable(Amount + 1,
                                          std::vector<int>(Coins.size(), -1));
    int CurrentAmount = 0;
    // Base case: zero amount needs zero coins.
    for (auto &MinCoin : DPTable[CurrentAmount]) {
      MinCoin = 0;
    }
    for (int CurrentAmount = 1; CurrentAmount <= Amount; CurrentAmount++) {
      for (int CurrentCoin = 0; CurrentCoin < Coins.size(); CurrentCoin++) {
        int CoinValue = Coins[CurrentCoin];
        auto SubAmount = CurrentAmount - CoinValue;
        if (SubAmount < 0) {
          continue;
        }
        auto MinValue = getMinValidValue(DPTable[SubAmount]);
        if (MinValue != -1) {
          DPTable[CurrentAmount][CurrentCoin] = MinValue + 1;
        }
      }
    }
    return getMinValidValue(DPTable.back());
  }

private:
  int getMinValidValue(const std::vector<int> &DPTableRow) {
    auto Ret = -1;
    for (auto Val : DPTableRow) {
      if (Val == -1) {
        continue;
      }
      if (Ret == -1) {
        Ret = Val;
        continue;
      }
      Ret = std::min(Ret, Val);
    }
    return Ret;
  }
};