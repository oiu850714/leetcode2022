#include "headers.hpp"

class Solution {
public:
  int missingNumber(std::vector<int> &Nums) {
    // See the leetcode solution.
    // Or: https://youtu.be/WnPLSRLSANE?t=162
    int Result = Nums.size();
    for (int i = 0; i < Nums.size(); i++) {
      Result ^= (i ^ Nums[i]);
    }
    return Result;
  }
};
