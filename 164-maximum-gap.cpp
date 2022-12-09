#include "headers.hpp"

class Solution {
public:
  int maximumGap(std::vector<int> &Nums) {
    if (Nums.size() == 1) {
      return 0;
    }

    // Use radix sort.
    radixSort_(Nums.begin(), Nums.end(),
               getMaxBitPos_(*std::max_element(Nums.begin(), Nums.end())));
    int Ret = Nums[1] - Nums[0];
    for (int i = 2; i < Nums.size(); i++) {
      Ret = std::max(Ret, Nums[i] - Nums[i - 1]);
    }

    return Ret;
  }

private:
  template <typename It> void radixSort_(It &&Beg, It &&End, int BitOrder) {
    if (BitOrder < 0) {
      return;
    }
    auto SecondBeg = std::partition(Beg, End, [BitOrder](auto Num) {
      return (Num & (1 << BitOrder)) == 0;
    });
    if (SecondBeg - Beg > 1) {
      radixSort_(Beg, SecondBeg, BitOrder - 1);
    }
    if (End - SecondBeg > 1) {
      radixSort_(SecondBeg, End, BitOrder - 1);
    }
  }

  int getMaxBitPos_(int N) {
    int Pos = 31;
    while ((N & (1 << Pos)) == 0) {
      Pos--;
    }
    return Pos;
  }
};
