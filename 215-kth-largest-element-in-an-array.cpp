#include "headers.hpp"

class Solution {
public:
  // Amortized O(n) solution.
  // Textbook: Algorithms Illuminated Part1 Ch6.
  // You can use std::nth_element.
  int findKthLargest(std::vector<int> &Nums, int K) {
    // Convert K to 0-based.
    K -= 1;

    int Beg = 0, End = Nums.size();
    std::random_device Generator;
    while (Beg < End) {
      auto PivotIdx = std::uniform_int_distribution(Beg, End - 1)(Generator);
      auto OrderOfPivot = partition_(Nums, Beg, End, PivotIdx);
      if (OrderOfPivot == K) {
        return Nums[OrderOfPivot];
      } else if (OrderOfPivot > K) {
        End = OrderOfPivot;
      } else {
        Beg = OrderOfPivot + 1;
      }
    }

    // Impossible.
    return -1;
  }

private:
  // You can use std::partition anyway.
  // [Beg, End)
  int partition_(std::vector<int> &Nums, int Beg, int End, int PivotIdx) {
    if (End - Beg == 1) {
      return Beg;
    }
    // Swap the pivot element with the last element of (the subinterval of) the
    // array.
    std::swap(Nums[PivotIdx], Nums[End - 1]);
    auto PivotVal = Nums[End - 1];
    // Invariant:
    //   i is the end of the left interval with value >= PivotVal.
    //   j is the end of the right interval with value < PivotVal; j is also the
    //   starting index of the unprocessed part.
    int i = Beg, j = Beg;
    for (; j < End - 1; j++) {
      if (Nums[j] >= PivotVal) {
        std::swap(Nums[i++], Nums[j]);
      }
    }
    // Make the pivot element in the right position.
    std::swap(Nums[i], Nums[End - 1]);
    return i;
  }
};
