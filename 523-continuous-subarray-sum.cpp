#include "headers.hpp"

class Solution {
public:
  bool checkSubarraySum(std::vector<int> &Nums, int K) {
    // The initial value deals with the case that there is a prefix with
    // summation of multiple of K.
    std::unordered_map<int, int> PrefixRemainderIdx{{0, -1}};

    // The argument is: There is a cont. subseq. with summation of multiple of
    // K, IF AND ONLY IF there is a pair of index i, j, such that the summation
    // of Nums[0...i] and Nums[0...j] is equal modulo K.
    auto Remainder = 0;
    for (size_t i = 0; i < Nums.size(); i++) {
      Remainder = (Remainder + Nums[i]) % K;
      if (!PrefixRemainderIdx.count(Remainder)) {
        PrefixRemainderIdx[Remainder] = i;
        continue;
      }
      if (i - PrefixRemainderIdx.at(Remainder) > 1) {
        return true;
      }
    }
    return false;
  }
};
