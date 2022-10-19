#include "headers.hpp"

class Solution {
public:
  bool isHappy(int N) {
    std::unordered_set<int> AppearedNumbers;
    while (true) {
      auto NewNumber = 0;
      while (N != 0) {
        auto LastDigit = N % 10;
        NewNumber += LastDigit * LastDigit;
        N /= 10;
      }
      if (AppearedNumbers.find(NewNumber) != AppearedNumbers.end()) {
        return false;
      }
      if (NewNumber == 1) {
        return true;
      }
      N = NewNumber;
      AppearedNumbers.insert(N);
    }
  }
};