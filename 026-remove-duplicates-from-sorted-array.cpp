#include "headers.hpp"

class Solution {
public:
  int removeDuplicates(std::vector<int> &Nums) {
    // Though test cases assume size() >= 1, but std::unique doest not.
    if (Nums.empty()) {
      return 0;
    }
    int NumUniqElementsSeenSoFar = 1;
    // The concept: the j-th UNIQUE element should be placed at Nums[j].
    // So use a variable to store the number of unique element we have seen.
    for (int i = 1; i < Nums.size(); i++) {
      if (Nums[i] != Nums[i - 1]) {
        NumUniqElementsSeenSoFar += 1;
        // Subtract 1 to convert to 0-based index.
        // e.g. The 2-th unique number should be stored in 2 - 1 = 1-th element.
        Nums[NumUniqElementsSeenSoFar - 1] = Nums[i];
      }
    }
    return NumUniqElementsSeenSoFar;
  }
};
