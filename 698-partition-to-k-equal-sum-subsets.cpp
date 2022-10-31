#include "headers.hpp"

class Solution {
public:
  bool canPartitionKSubsets(std::vector<int> &Nums, int K) {
    std::sort(Nums.begin(), Nums.end(),
              std::greater<int>()); // Picking bigger elements first can reduce
                                    // runtime branch drastically.
    auto Total = std::accumulate(Nums.begin(), Nums.end(), 0);
    if (Total % K) {
      return false;
    }
    K_ = K;
    Expect_ = Total / K;
    Nums_ = &Nums;
    std::string NumsUsage(Nums.size(), '0');
    std::unordered_map<std::string, bool> DPTable;
    return backtrack_(0, 0, 0, NumsUsage, DPTable);
  }

private:
  int K_;
  int Expect_;
  std::vector<int> const *Nums_;
  bool backtrack_(int NumCompletedSets, int Index, int CurrSum,
                  std::string &NumsUsage,
                  std::unordered_map<std::string, bool> &DPTable) {
    if (NumCompletedSets == K_ - 1) {
      return true;
    }

    if (CurrSum > Expect_) {
      return false;
    }

    // We choose to first enter the recursion and see whether we have calculated
    // the result, instead of searching the cache first and call the recursion
    // therefore.
    if (DPTable.find(NumsUsage) != DPTable.end()) {
      return DPTable.at(NumsUsage);
    }

    if (CurrSum == Expect_) {
      // We have successfully build a new subset with sum equal to Expect_.
      return DPTable[NumsUsage] = backtrack_(NumCompletedSets + 1,
                                             0, // Reset Index.
                                             0, // Reset CurrSum.
                                             NumsUsage, DPTable);
    }

    for (int i = Index; i < Nums_->size(); i++) {
      if (NumsUsage[i] == '0') {
        NumsUsage[i] = '1';
        if (backtrack_(NumCompletedSets, i + 1, CurrSum + (*Nums_)[i],
                       NumsUsage, DPTable)) {
          return true;
        }
        NumsUsage[i] = '0'; // Restore state.
      }
    }
    // At this point, all branches of NumsUsage have been searched and return
    // false.
    return DPTable[NumsUsage] = false;
  }
};
