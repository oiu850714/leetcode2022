#include "headers.hpp"

class Solution {
public:
  bool canPartition(std::vector<int> &Nums) {
    auto Total = std::accumulate(Nums.begin(), Nums.end(), 0);
    if (Total & 1) {
      // Total sum is odd, the numbers can never be partitioned into two subset
      // with equal values.
      return false;
    }

    auto ExpectedSum = Total >> 1;
    // Since the assumption is that each number is positive, ExpectedSum is also
    // positive.
    std::vector<std::vector<bool>> DPTable(ExpectedSum + 1,
                                           std::vector<bool>(Nums.size()));

    // The problem can be reduced to "can we find a subset of numbers in Nums
    // such that the sum is ExpectedSum"(so the remaining numbers also sum to
    // ExpectedSum).
    for (int i = 0; i < Nums.size(); ++i) {
      // Base case: we can pick "zero" elements to sum to zero.
      DPTable[0][i] = true;
    }
    for (auto Sum = 1; Sum <= ExpectedSum; ++Sum) {
      for (int i = 0; i < Nums.size(); ++i) {
        auto SubSum = Sum - Nums[i];
        if (i == 0) {
          // If i == 0, then we can only use the first number.
          // Then subtracting from Nums[0], SubSum must be equal to zero.
          DPTable[Sum][i] = SubSum == 0;
          continue;
        }

        if (SubSum < 0) {
          // The numbers before the i-th number can never sum to negative.
          // So we can only use the subproblem that the first i - 1 numbers sum
          // to Sum.
          DPTable[Sum][i] = DPTable[Sum][i - 1];
          continue;
        }

        // Otherwise, two subproblems are available: enclude i-th number or not.
        // If including i-th number, then the subproblem is "using the first i -
        // 1 numbers to get the value SubSum". If not, then the subproblem is
        // "using the first i - 1 numbers to get the value Sum".
        DPTable[Sum][i] = DPTable[SubSum][i - 1] || DPTable[Sum][i - 1];
      }
    }
    return DPTable[ExpectedSum][Nums.size() - 1];
  }
};