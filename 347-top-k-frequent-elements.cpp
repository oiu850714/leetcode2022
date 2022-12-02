#include "headers.hpp"

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &Nums, int K) {
    std::unordered_map<int, int> ValCount;
    for (auto Num : Nums) {
      ValCount[Num]++;
    }

    std::vector<std::pair<int, int>> CountVal;
    for (auto [Val, Count] : ValCount) {
      CountVal.push_back({Count, Val});
    }

    // This is the same approach as 215.
    // But just use std::nth_element instead.
    // Another approach is convert CountVal to a max heap and return first top K
    // elements.
    std::nth_element(CountVal.begin(), CountVal.begin() + K, CountVal.end(),
                     std::greater());
    std::vector<int> Ret(K);
    for (int i = 0; i < K; i++) {
      Ret[i] = CountVal[i].second;
    }
    return Ret;
  }
};
