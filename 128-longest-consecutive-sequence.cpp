#include "headers.hpp"

class Solution {
public:
  int longestConsecutive(std::vector<int> &Nums) {
    if (Nums.empty()) {
      return 0;
    }

    std::unordered_set<int> NumsHash(Nums.begin(),
                                     Nums.end()); // Support O(1) lookup.
    int MaxLen = 1;
    for (auto Num : Nums) {
      if (NumsHash.count(Num - 1)) {
        // if Nums contains Num - 1, then we do not need to check the
        // (consecutive) sequence starting from Num, since the sequence starting
        // from Num must be a shorter subsequence of the sequence starting from
        // Num - 1.
        continue;
      }

      int NewSeqLen = 1;
      int SeqLast = Num;
      while (NumsHash.count(SeqLast + 1)) {
        NewSeqLen += 1;
        SeqLast += 1;
      }
      MaxLen = std::max(MaxLen, NewSeqLen);
    }
    return MaxLen;
  }
};
