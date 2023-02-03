#include "headers.hpp"

class Solution {
public:
  std::vector<int> singleNumber(std::vector<int> &Nums) {
    auto XOR = std::accumulate(Nums.begin(), Nums.end(), 0, std::bit_xor());
    auto FirstDiff =
        (XOR != std::numeric_limits<int>::min()) ? (XOR & -XOR) : XOR;
    auto FirstNum = 0;
    for (auto Num : Nums) {
      if (Num & FirstDiff) {
        FirstNum ^= Num;
      }
    }
    return {FirstNum, XOR ^ FirstNum};
  }
};
