#include "headers.hpp"

class Solution {
public:
  int averageValue(std::vector<int> &Nums) {
    int Sum = 0, Count = 0;
    for (auto Num : Nums) {
      if (evenAndDiv3_(Num)) {
        Sum += Num;
        Count += 1;
      }
    }
    return Count ? Sum / Count : 0;
  }

  bool evenAndDiv3_(int Num) {
    if (Num & 1) {
      return false;
    }

    int SumDigits = 0;
    while (Num) {
      SumDigits += Num % 10;
      Num /= 10;
    }
    return SumDigits % 3 == 0;
  }
};
