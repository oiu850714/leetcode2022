#include "headers.hpp"

class Solution {
public:
  int firstMissingPositive(std::vector<int> &Nums) {
    auto isOutOfRange = [N = Nums.size()](auto Val) {
      return Val < 1 || Val > N;
    };

    std::replace_if(Nums.begin(), Nums.end(), isOutOfRange, Nums.size() + 1);
    for (auto Num : Nums) {
      auto NumAbs = std::abs(Num), Idx = NumAbs - 1;
      if (!isOutOfRange(NumAbs)) {
        Nums[Idx] = -std::abs(Nums[Idx]);
      }
    }
    auto isPositive = [](auto E) { return E > 0; };
    return std::distance(Nums.begin(),
                         std::find_if(Nums.begin(), Nums.end(), isPositive)) +
           1;
  }
};
