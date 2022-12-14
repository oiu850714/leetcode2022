#include "headers.hpp"

class Solution {
public:
  ListNode *reverseList(ListNode *Head) {
    if (!Head) {
      // There is testcase for empty list.
      return Head;
    }
    return reverseListRecursive_(Head).first;
  }

private:
  // Return Head and (address of) tail's next.
  std::pair<ListNode *, ListNode **> reverseListRecursive_(ListNode *Head) {
    if (!Head->next) {
      return {Head, &Head->next};
    }

    auto [ReversedHead, Tail] = reverseListRecursive_(Head->next);
    *Tail = Head;
    Head->next = nullptr;
    return {ReversedHead, &Head->next};
  }
};