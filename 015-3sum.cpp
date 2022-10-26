#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &Nums) {
    std::sort(Nums.begin(), Nums.end());
    std::vector<std::vector<int>> Ret;
    // By assumption, Nums.size() >= 3.
    for (int First = 0; First < Nums.size() - 2; First++) {
      if (Nums[First] > 0) {
        // If Nums[First] > 0, then all elements right of Nums[First] are also
        // positive, so the sum of any three of them cannot be zero.
        break;
      }
      if (First > 0 && Nums[First] == Nums[First - 1]) {
        // If the new selected first numbers is still the same as before, then
        // we will find duplicate triplets, using this "same-first-element" and
        // the second and third elements of the correspodning duplicate
        // triplets.
        continue;
      }
      for (int Second = First + 1, Third = Nums.size() - 1; Second < Third;) {
        const auto Result = Nums[First] + Nums[Second] + Nums[Third];
        if (Result == 0) {
          Ret.push_back({Nums[First], Nums[Second++], Nums[Third--]});
          // Again, the two loops below prevent duplicate triplets.
          while (Second < Third && Nums[Second] == Nums[Second - 1]) {
            Second++;
          }
          while (Second < Third && Nums[Third] == Nums[Third + 1]) {
            Third--;
          }
        } else if (Result > 0) {
          Third--;
        } else {
          Second++;
        }
      }
    }
    return Ret;
  }
};