#include "headers.hpp"

class Solution {
public:
  int coinChange(std::vector<int> &Coins, const int Amount) {
    std::vector<int> DPTable(Amount + 1);
    // Base case: zero amount needs zero coins.
    DPTable[0] = 0;

    for (auto CurrentAmount = 1; CurrentAmount <= Amount; CurrentAmount++) {
      int NumOfCoins = -1;
      for (auto CoinValue : Coins) {
        auto SubAmount = CurrentAmount - CoinValue;
        if (SubAmount < 0) {
          continue;
        }

        if (DPTable[SubAmount] == -1) {
          // The corresponding subproblem is still invalid.
          continue;
        }

        // We need to first check whether NumOfCoins has ever been set.
        if (NumOfCoins == -1) {
          NumOfCoins = DPTable[SubAmount] + 1;
          continue;
        }
        // std::min makes sense only when NumOfCoins has been set to a
        // nonnegative.
        NumOfCoins = std::min(NumOfCoins, DPTable[SubAmount] + 1);
      }
      DPTable[CurrentAmount] = NumOfCoins;
    }
    return DPTable[Amount];
  }
};