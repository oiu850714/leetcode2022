#include "headers.hpp"

class Solution {
public:
  int numberOfArithmeticSlices(std::vector<int> &Nums) {
    if (Nums.size() < 3) {
      return 0;
    }
    // <LastNumOfSeq, <Diff, Count>>.
    std::unordered_map<int, std::unordered_map<int64_t, int>> Sol;
    // <LastNum, <Diff, Count>>.
    // Store all possible pairs.
    // We need to store them, since some of them + new number create a newly
    // 3-element subsequence.
    std::unordered_map<int, std::unordered_map<int64_t, int>> CurrPairs;

    for (int i = 1; i < Nums.size(); i++) {
      // int64_t to prevent overflow of the computation of Diff.
      // E.g. input: [0,2000000000,-294967296].
      int64_t NewLastNum = Nums[i];
      decltype(Sol) NewSol;

      // New solutions by appending NewLastNum to seqs of subproblems.
      for (const auto &[LastNumOfSeq, Seqs] : Sol) {
        auto Diff = NewLastNum - LastNumOfSeq;
        if (Seqs.count(Diff)) {
          NewSol[NewLastNum][Diff] += Seqs.at(Diff);
        }
      }

      // New solutions by appending NewLastNum of current pairs.
      for (const auto &[LastNumOfPair, Pairs] : CurrPairs) {
        auto Diff = NewLastNum - LastNumOfPair;
        if (Pairs.count(Diff)) {
          NewSol[NewLastNum][Diff] += Pairs.at(Diff);
        }
      }

      // Add new sequences to current solution.
      // Since we only add O(n) items in new sol, the merge operation is still
      // O(n).
      for (const auto &[LastNum, Seqs] : NewSol) {
        for (auto [Diff, Count] : Seqs) {
          Sol[LastNum][Diff] += Count;
        }
      }

      // Add new pairs.
      for (int j = 0; j < i; j++) {
        CurrPairs[NewLastNum][NewLastNum - Nums[j]]++;
      }
    }

    int Ret = 0;
    for (const auto &[LastNum, Seqs] : Sol) {
      for (auto [Diff, Count] : Seqs) {
        Ret += Count;
      }
    }
    return Ret;
  }
};
