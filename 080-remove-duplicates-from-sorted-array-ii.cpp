#include "headers.hpp"

class Solution {
public:
  int removeDuplicates(std::vector<int> &Nums) {
    // Though test cases assume size() >= 1, but std::unique doest not.
    if (Nums.empty()) {
      return 0;
    }

    int Counter = 1;
    int InsertIdx = 1;
    for (int i = 1; i < Nums.size(); i++) {
      if (Nums[i] != Nums[i - 1]) {
        Counter = 1;
        Nums[InsertIdx++] = Nums[i];
      } else {
        if (Counter == 1) {
          Counter++;
          Nums[InsertIdx++] = Nums[i];
        }
      }
    }
    return InsertIdx;
  }
};
