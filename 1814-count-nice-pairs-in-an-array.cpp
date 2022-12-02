#include "headers.hpp"

class Solution {
public:
  // Althoug the definition of "nice" pair is different, the logic of hashtable
  // usage is similar to 2364.
  int countNicePairs(std::vector<int> &Nums) {
    long long NumValid = 0;
    std::unordered_map<int, int> DiffCount;
    for (int i = 0; i < Nums.size(); i++) {
      auto Diff = Nums[i] - reverse_(Nums[i]);
      NumValid += DiffCount[Diff];
      DiffCount[Diff]++;
    }

    return NumValid % 1000000007;
  }

private:
  // Just use built-in.
  // Note that, since input value can only be 0 <= Nums <= 109, the reverse
  // integer will be NEVER overflow on int;
  // This is different from the old problem 007.
  int reverse_(int Num) {
    auto STR = std::to_string(Num);
    std::reverse(STR.begin(), STR.end());
    return std::stoi(STR);
  }
};
