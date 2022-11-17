#include "headers.hpp"

class Solution {
public:
  void rotate(std::vector<int> &Nums, int K) {
    K %= Nums.size(); // K can be larger than array size.
    std::reverse(Nums.begin(), Nums.end());
    std::reverse(Nums.begin(), Nums.begin() + K);
    std::reverse(Nums.begin() + K, Nums.end());
  }
};
