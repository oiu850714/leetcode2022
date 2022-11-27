#include "headers.hpp"

class Solution {
public:
  bool containsDuplicate(std::vector<int> &Nums) {
    std::unordered_set<int> Hash;
    for (auto Num : Nums) {
      if (Hash.count(Num)) {
        return true;
      }
      Hash.insert(Num);
    }
    return false;
  }
};
