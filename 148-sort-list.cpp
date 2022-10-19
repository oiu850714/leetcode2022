#include "headers.hpp"

class Solution {
public:
  ListNode *sortList(ListNode *Head) {
    int MergingSize = 1;
    while (true) {
      auto Curr = Head;
      bool HasMerged = false;
      ListNode *NewListHead = nullptr, **NewListTail = &NewListHead;
      while (Curr != nullptr) {
        ListNode *FirstHalf, *SecondHalf;
        Curr = cutList(&Curr, &FirstHalf, MergingSize);
        // FirstHalf always has at least one node, because at the beginning of
        // the loop, Curr is not nullptr.
        // But SecondHalf may be nullptr because we move MergingSize nodes from
        // Curr-list into FirstHalf-list.
        Curr = cutList(&Curr, &SecondHalf, MergingSize);
        if (SecondHalf == nullptr) {
          // If the second list is empty, we just concat the first list to the
          // tail of the new list.
          *NewListTail = FirstHalf;
          break;
        }
        // Otherwise we merge the two (nonempty) lists and concat the result to
        // the tail of the new list.
        *NewListTail = mergeTwoLists(FirstHalf, SecondHalf);
        // And we need to advance the NewListTail to the tail of the new merged
        // nodes.
        while (*NewListTail != nullptr) {
          NewListTail = &(*NewListTail)->next;
        }
        HasMerged = true;
      }
      if (!HasMerged) {
        break;
      }
      Head = NewListHead;
      MergingSize *= 2;
    }
    return Head;
  }

private:
  // Copied from 021.
  ListNode *mergeTwoLists(ListNode *List1, ListNode *List2) {
    ListNode *Ret = nullptr;
    auto Curr = &Ret;
    while (List1 != nullptr && List2 != nullptr) {
      if (List1->val <= List2->val) {
        *Curr = List1;
        Curr = &List1->next;
        List1 = List1->next;
      } else {
        *Curr = List2;
        Curr = &List2->next;
        List2 = List2->next;
      }
    }

    // Concate remaining nodes
    *Curr = List1 != nullptr ? List1 : List2;

    return Ret;
  }

  // Cut the first Size nodes of the Head, and return the first(remaining) head
  // after these nodes.
  // Make Dest point to these cutted nodes, and make the last of these cutted
  // nodes point to nullptr.
  ListNode *cutList(ListNode **Head, ListNode **Dest, int Size) {
    *Dest = *Head;
    while (Size-- && *Head != nullptr) {
      Head = &(*Head)->next;
    }
    // After the loop, the Head is on the next-pointer in the last node of the
    // cutted part, and that next-pointer of course points to the first node of
    // the remaining part.
    auto RemainingHead = *Head;
    // So we copy and return the value of that pointer to return the first node
    // of remaining part, but also make that pointer point to nullptr to
    // actually "cut" the list.
    *Head = nullptr;
    return RemainingHead;
  }
};