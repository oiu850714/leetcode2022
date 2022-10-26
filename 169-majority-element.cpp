#include "headers.hpp"

class Solution {
public:
  int majorityElement(std::vector<int> &Nums) {
    int Curr = 0;  // Giving value just for the sake of variable initialization.
    int Count = 0; // Represent the availavble Currs' that can be cancelled out
                   // (or paired out).
    for (auto Num : Nums) {
      if (Count == 0) {
        Count = 1;
        Curr = Num;
      } else {
        Count += Curr == Num ? 1 : -1;
      }
    }
    return Curr;
  }
};