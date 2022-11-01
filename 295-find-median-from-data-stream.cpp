#include "headers.hpp"

class MedianFinder {
  // Refer to: Tim Roughgarden: Algorithms Illuminated part 2, 10.3.3.
public:
  void addNum(int Num) {
    if (LessHalf_.empty()) {
      LessHalf_.push(Num);
      return;
    }

    // If LessHalf_ already has more elements.
    if (LessHalf_.size() > GreaterHalf_.size()) {
      if (Num < LessHalf_.top()) {
        // If we still push the element to LessHalf_, then after the operation,
        // we need to extract the top of LessHalf_ to GreaterHalf_, to make the
        // two heaps have the same number of elements.
        LessHalf_.push(Num);
        auto LargestInLess = LessHalf_.top();
        LessHalf_.pop();
        GreaterHalf_.push(LargestInLess);
      } else {
        // Just push to GreaterHalf_, such that the number of elements in the
        // two heaps are the same.
        GreaterHalf_.push(Num);
      }
      // Else, LessHalf_ has less or equal elements as GreaterHalf_.
      // In either cases, if we push Num to GreaterHalf_, we need to extract the
      // smallest element from GreaterHalf_ to LessHalf_.
    } else {
      if (Num < LessHalf_.top()) {
        LessHalf_.push(Num);
      } else {
        GreaterHalf_.push(Num);
        auto SmallestInGreater = GreaterHalf_.top();
        GreaterHalf_.pop();
        LessHalf_.push(SmallestInGreater);
      }
    }
  }

  double findMedian() {
    if ((LessHalf_.size() + GreaterHalf_.size()) % 2) {
      return LessHalf_.top();
    } else {
      return (double)(LessHalf_.top() + GreaterHalf_.top()) / 2;
    }
  }

private:
  // GreaterHalf_ is a min-heap.
  // And LessHalf_ is a max-heap.
  // The invariant is:
  // 1. If total numbers is odd, then LessHalf_ has one more element.
  // 2. Otherwise, the two heaps have the same number of elements.
  std::priority_queue<int, std::vector<int>, std::greater<int>> GreaterHalf_;
  std::priority_queue<int> LessHalf_;
};