#include "headers.hpp"

class Solution {
public:
  int subarraySum(std::vector<int> &Nums, int K) {
    std::unordered_map<int, int> ParsedPrefixSumCount;
    auto CurrPrefixSum = 0;
    auto TotalCount = 0;
    for (auto Num : Nums) {
      CurrPrefixSum += Num;
      // The whole prefix sum from the 1st element to this number is equal to K.
      if (CurrPrefixSum == K) {
        TotalCount += 1;
      }

      auto RemainSum = CurrPrefixSum - K;
      // The differences between CurrPrefixSum and all prefix sums that sum to
      // RemainSum are also valid subarrays.
      if (ParsedPrefixSumCount.find(RemainSum) != ParsedPrefixSumCount.end()) {
        TotalCount += ParsedPrefixSumCount.at(RemainSum);
      }
      ParsedPrefixSumCount[CurrPrefixSum]++;
    }
    return TotalCount;
  }
};