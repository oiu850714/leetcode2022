#include "headers.hpp"

// Definition for a Node.
class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
};

class Solution {
public:
  Node *flatten(Node *Head) {
    for (auto Curr = Head; Curr; Curr = Curr->next) {
      if (Curr->child) {
        // Pluck the child into next + update internal pointers.
        auto OldNext = Curr->next;
        Curr->next = Curr->child;
        Curr->next->prev = Curr;
        Curr->child = nullptr;

        // Then visit to the end of the old child sequence.
        auto LastChildNode = Curr->next;
        while (LastChildNode->next) {
          LastChildNode = LastChildNode->next;
        }

        // Then paste the old next to that end + update internal pointers.
        LastChildNode->next = OldNext;
        if (OldNext) {
          OldNext->prev = LastChildNode;
        }

        // Then when Curr continues to go next, it still can encounter the old
        // child's non-flattened sequence, if exists.
      }
    }
    return Head;
  }
};
