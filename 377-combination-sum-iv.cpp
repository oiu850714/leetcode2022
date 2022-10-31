#include "headers.hpp"

class Solution {
public:
  // By assumption, the numbers in Nums are DISTINCT.
  // Note that the problem says we should consider is combination as a SEQUENCE,
  // hence the order of selected elements in the combination matters.
  int combinationSum4(std::vector<int> &Nums, int Target) {
    // XXX: Some result in the DP table may exceed 32-bit integer, but the
    // answer is guaranteed to fit in 32-bit integer.
    // So store uint64_t instead of int.
    std::vector<uint64_t> DPTable(Target + 1);
    DPTable[0] = 1; // sequence that sums to 0, i.e., empty sequence.
    for (uint64_t DpNum = 1; DpNum <= Target; DpNum++) {
      for (auto SelectNum : Nums) {
        if (DpNum < SelectNum) {
          continue;
        }
        auto RemainNum = DpNum - SelectNum;
        DPTable[DpNum] += DPTable[RemainNum];
      }
    }
    return DPTable[Target];
  }
};