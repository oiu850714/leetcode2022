#include "headers.hpp"

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int> &Nums, int K) {
    std::unordered_map<int, int> HashTable; // Num -> Last Occurred Index.
    for (int i = 0; i < Nums.size(); i++) {
      if (HashTable.count(Nums[i]) &&
          std::abs(HashTable.at(Nums[i]) - i) <= K) {
        return true;
      }
      HashTable[Nums[i]] = i;
    }
    return false;
  }
};