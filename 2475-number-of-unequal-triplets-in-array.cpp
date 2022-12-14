#include "headers.hpp"

class Solution {
public:
  int unequalTriplets(std::vector<int> &Nums) {
    // <Num, Count>
    std::unordered_map<int, int> NumCount;
    for (auto Num : Nums) {
      NumCount[Num]++;
    }

    // The code below essentially runs the three-nested-loop in this order:
    // for (int j = 0; j < NumCount.size(); j++) {     // pick middle first
    //   for (int i = 0; j < j; i++) {                 // then first
    //     for (int k = j; k < NumCount.size(); k++) { // then third
    //       ...
    //     }
    //   }
    // }
    // That is, first PICK MIDDLE ELEMENT, then pick first and third elements.
    // But we can just save the sum of all possible first elements in LeftCount,
    // and the sum (or sum minus the value of second element) of all possible
    // third elements in RightCount, respectively.
    int TotalCount = Nums.size();
    auto LeftCount = 0, RightCount = TotalCount;
    auto Ret = 0;
    for (auto [Num, Count] : NumCount) {
      Ret += LeftCount * Count * (RightCount - Count);
      LeftCount += Count;
      RightCount -= Count;
    }
    return Ret;
  }
};
