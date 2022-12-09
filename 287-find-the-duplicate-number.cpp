#include "headers.hpp"

class Solution {
public:
  // Related: 142.
  int findDuplicate(std::vector<int> &Nums) {
    int FastPtr = Nums[Nums[0]], SlowPtr = Nums[0];
    while (FastPtr != SlowPtr) {
      FastPtr = Nums[Nums[FastPtr]];
      SlowPtr = Nums[SlowPtr];
    }
    return cycleStart_(Nums, 0, SlowPtr);
  }

private:
  int cycleStart_(const std::vector<int> &Nums, int Head, int EncounterPt) {
    while (Head != EncounterPt) {
      Head = Nums[Head];
      EncounterPt = Nums[EncounterPt];
    }
    return Head;
  }
};
