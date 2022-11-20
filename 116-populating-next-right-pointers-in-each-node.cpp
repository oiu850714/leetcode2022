#include "headers.hpp"

class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}
  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
  Node *connect(Node *Root) {
    std::vector<Node *> Queue;
    Queue.push_back(Root);
    while (!Queue.empty()) {
      decltype(Queue) NextLevelQueue;
      for (int i = 0; i < Queue.size(); i++) {
        auto Node = Queue[i];
        if (Node == nullptr) {
          continue;
        }

        NextLevelQueue.push_back(Node->left);
        NextLevelQueue.push_back(Node->right);
        if (i != Queue.size() - 1) {
          Node->next = Queue[i + 1];
        }
      }
      Queue.swap(NextLevelQueue);
    }

    return Root;
  }
};