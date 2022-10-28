#include "headers.hpp"

class Solution {
public:
  void nextPermutation(std::vector<int> &Nums) {
    // If Nums is reversed sorted, then it's greatest permutation.
    if (std::is_sorted(Nums.begin(), Nums.end(), std::greater())) {
      std::reverse(Nums.begin(), Nums.end());
      return;
    }

    // Else, Nums is not reversed sorted, so there exists an increasing
    // subsequence in Nums.
    // Two cases: The increasing subsequence can be at the end or not.
    if (isIncreasingAtTheEnd_(Nums)) {
      // If Nums is increasing at the end, then the following code swap the
      // first number, counting from the end, that is strictly less than the
      // last number of Nums.
      // Maybe it's intuitive to see that the swap makes Nums the next
      // permutation.
      for (int i = Nums.size() - 1; i - 1 >= 0; i--) {
        if (Nums[i] == Nums[i - 1]) {
          continue;
        }
        std::swap(Nums[i], Nums[i - 1]);
        return;
      }
    } else {
      // Otherwise, Nums is decreasing at the end.
      // In particular, there EXISTS a number BEFORE this decreasing subsequence
      // such that it's less than the maximum of the subsequence.
      // (It's must exist, otherwise the whole Nums is decreasing, a
      // contradiction.)
      for (int i = Nums.size() - 1; i - 1 >= 0; i--) {
        // Then we found that number, which is Nums[i - 1].
        if (Nums[i] <= Nums[i - 1]) {
          continue;
        }
        // And swap Nums[i - 1] with the number, counting from the end, that
        // it's strictly greater than Nums[i - 1].
        // And we sort Nums[i] to the end.
        // Again maybe it's intuitive to see that the swap and the sort make
        // Nums the next permutation.
        for (int j = Nums.size() - 1; j >= 0; j--) {
          if (Nums[j] <= Nums[i - 1]) {
            continue;
          }
          std::swap(Nums[i - 1], Nums[j]);
          std::sort(Nums.begin() + i, Nums.end());
          return;
        }
      }
    }
  }

private:
  bool isIncreasingAtTheEnd_(const std::vector<int> &Nums) {
    for (int i = Nums.size() - 1; i - 1 >= 0; i--) {
      if (Nums[i] == Nums[i - 1]) {
        continue;
      } else if (Nums[i] > Nums[i - 1]) {
        return true;
      } else {
        return false;
      }
    }
    return false;
  }
};