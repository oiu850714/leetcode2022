#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &Nums, int Target) {
    if (Nums.size() < 4) {
      return {};
    }
    std::vector<std::vector<int>> Ret;
    std::sort(Nums.begin(), Nums.end());

    // The concept is like 015. Three-Sum.
    for (int FirNumIt = 0; FirNumIt < Nums.size() - 3; FirNumIt++) {
      if (FirNumIt > 0 && Nums[FirNumIt] == Nums[FirNumIt - 1]) {
        continue;
      }
      for (int SecNumIt = FirNumIt + 1; SecNumIt < Nums.size() - 2;
           SecNumIt++) {
        if (SecNumIt > FirNumIt + 1 && Nums[SecNumIt] == Nums[SecNumIt - 1]) {
          continue;
        }
        int ThrNumIt = SecNumIt + 1, ForNumIt = Nums.size() - 1;
        while (ThrNumIt < ForNumIt) {
          // Conversion to prevent overflow.
          auto Sum = (int64_t)Nums[FirNumIt] + Nums[SecNumIt] + Nums[ThrNumIt] +
                     Nums[ForNumIt];
          if (Sum == Target) {
            Ret.push_back({Nums[FirNumIt], Nums[SecNumIt], Nums[ThrNumIt++],
                           Nums[ForNumIt--]});
            while (ThrNumIt < ForNumIt &&
                   Nums[ThrNumIt] == Nums[ThrNumIt - 1]) {
              ThrNumIt++;
            }
            while (ThrNumIt < ForNumIt &&
                   Nums[ForNumIt] == Nums[ForNumIt + 1]) {
              ForNumIt--;
            }
          } else if (Sum > Target) {
            ForNumIt--;
          } else {
            ThrNumIt++;
          }
        }
      }
    }
    return Ret;
  }
};
