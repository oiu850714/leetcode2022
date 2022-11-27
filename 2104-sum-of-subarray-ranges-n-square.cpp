#include "headers.hpp"

class Solution {
public:
  long long subArrayRanges(std::vector<int> &Nums) {
    long long Ret = 0;
    for (int Beg = 0; Beg < Nums.size(); Beg++) {
      // Store the max and min of interval Beg, End for all Beg and End.
      auto Max = Nums[Beg], Min = Nums[Beg];
      for (int End = Beg + 1; End < Nums.size(); End++) {
        Min = std::min(Min, Nums[End]);
        Max = std::max(Max, Nums[End]);
        Ret += Max - Min;
      }
    }

    return Ret;
  }
};
