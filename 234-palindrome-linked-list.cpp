#include "headers.hpp"

// TODO: The O(1) space solution need to reverse half of the list
// "in-place", and can"not" use recursion because recursion is implicitly O(n)
// space.
class Solution {
public:
  bool isPalindrome(ListNode *Head) {
    // Just implement an easy one now.
    std::vector<int> Values;
    while (Head) {
      Values.push_back(Head->val);
      Head = Head->next;
    }
    for (int i = 0; i < Values.size() / 2; i++) {
      if (Values[i] != Values[Values.size() - 1 - i]) {
        return false;
      }
    }
    return true;
  }
};