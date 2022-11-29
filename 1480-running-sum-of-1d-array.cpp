#include "headers.hpp"

// Just a basic question to help know the existence of some cool algo in
// <algorithm>

class Solution {
public:
  std::vector<int> runningSum(const std::vector<int> &Nums) {
    std::vector<int> Ret(Nums.size());
    std::partial_sum(Nums.begin(), Nums.end(), Ret.begin());
    return Ret;
  }
};
