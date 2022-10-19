#include "headers.hpp"

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    // range representation: [beg, end)
    auto beg = nums.begin(), end = nums.end();
    while (end - beg >= 1) { // the interval has at least one element
      auto mid = beg + (end - beg) / 2;
      if (*mid == target) {
        return mid - nums.begin();
      }
      if (*mid < target) {
        // beg should always point the first element of the remaining intervel.
        // Now that mid element is not what we want, beg should point the
        // element "after" mid element, i.e. beg should become mid + 1
        beg = mid + 1;
      } else {
        // end should always point the element "after" the last element of the
        // remaining intervel. Now that mid element is not what we want, the
        // last element of the remaining interval is the element "before" the
        // mid element, so end should pointer the position "after" this element,
        // i.e. end should point mid element.
        end = mid;
      }
    }
    return -1;
  }
};