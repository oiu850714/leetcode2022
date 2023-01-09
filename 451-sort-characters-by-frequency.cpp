#include "headers.hpp"

class Solution {
public:
  std::string frequencySort(std::string S) {
    std::unordered_map<char, int> CharCount;
    for (auto C : S) {
      CharCount[C]++;
    }
    std::vector<std::pair<char, int>> Vec(CharCount.begin(), CharCount.end());
    // #Elements < 256, so sort is FAST.
    std::sort(Vec.begin(), Vec.end(), [](const auto &P1, const auto &P2) {
      return P1.second > P2.second;
    });
    std::string Ret;
    for (auto [Char, Count] : Vec) {
      Ret += std::string(Count, Char);
    }
    return Ret;
  }
};
