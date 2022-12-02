#include "headers.hpp"

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &Nums, int K) {
    std::unordered_map<int, int> ValCount;
    for (auto Num : Nums) {
      ValCount[Num]++;
    }

    // Notice the + 1 offset.
    std::vector<std::vector<int>> FreqBucket(Nums.size() + 1);
    for (auto [Val, Count] : ValCount) {
      FreqBucket[Count].push_back(Val);
    }

    std::vector<int> Ret;
    for (int i = FreqBucket.size() - 1; i >= 0; i--) {
      for (auto Val : FreqBucket[i]) {
        Ret.push_back(Val);
        if (Ret.size() == K) {
          return Ret;
        }
      }
    }
    return Ret;
  }
};
