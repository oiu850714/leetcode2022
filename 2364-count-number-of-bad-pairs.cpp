#include "headers.hpp"

class Solution {
public:
  long long countBadPairs(const std::vector<int> &Nums) {
    // We count the number of valid pairs instead.
    // By definition, (i, j) is VALID, if and only if,
    // Nums[j] - Nums[i] == j - i.
    // But this equation is equivalent to Nums[j] - j == Nums[i] - i.
    // Then we can check that, given new index i, how many index 0 <= j <= i - 1
    // seen so far have the property s.t. Nums[j] - j == Nums[i] - i.
    // The count can be saved in hash table.

    // Store <Difference, Count> where Difference is Nums[j] - j for all j
    // seen so far.
    std::unordered_map<int, int> DiffCount;
    long long NumValid = 0;
    for (int i = 0; i < Nums.size(); i++) {
      NumValid += DiffCount[Nums[i] - i];
      DiffCount[Nums[i] - i]++;
    }
    return (Nums.size() * (Nums.size() - 1)) / 2 - NumValid;
  }
};
