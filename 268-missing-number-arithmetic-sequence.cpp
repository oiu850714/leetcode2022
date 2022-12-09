#include "headers.hpp"

class Solution {
public:
  int missingNumber(std::vector<int> &Nums) {
    // See the leetcode solution.
    // Or: https://youtu.be/WnPLSRLSANE?t=482
    int SeqSum = (Nums.size()) * (Nums.size() + 1) / 2;
    int ArrSum = 0;
    for (auto Num : Nums) {
      ArrSum += Num;
    }
    return SeqSum - ArrSum;
  }
};
