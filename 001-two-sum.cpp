#include "headers.hpp"

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &Nums, int Target) {
    std::unordered_map<int, int> IndicesOfPrevElements;
    for (auto SecondNumIdx = 0; SecondNumIdx < Nums.size(); SecondNumIdx++) {
      auto SecondNum = Nums[SecondNumIdx], FirstNum = Target - SecondNum;
      if (IndicesOfPrevElements.find(FirstNum) != IndicesOfPrevElements.end()) {
        return {SecondNumIdx, IndicesOfPrevElements[FirstNum]};
      } else {
        IndicesOfPrevElements.emplace(SecondNum, SecondNumIdx);
      }
    }

    // Never happen by the assumption of the unique existence of the solution.
    throw std::exception();
  }
};