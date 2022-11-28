#include "headers.hpp"

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  Node *cloneGraph(Node *Start) {
    if (!Start) {
      return nullptr;
    }

    // OldNode, Correponding Copy Node.
    std::unordered_map<Node *, Node *> Visited;
    std::vector<std::pair<Node *, Node *>> Queue;
    auto CopyStart = new Node(Start->val);
    Queue.push_back({Start, CopyStart});
    Visited.insert({Start, CopyStart});
    while (!Queue.empty()) {
      std::vector<std::pair<Node *, Node *>> NextQueue;
      for (auto [OldNode, CopyNode] : Queue) {
        for (auto OldAdjNode : OldNode->neighbors) {
          if (!Visited.count(OldAdjNode)) {
            auto NewAdjNode = new Node(OldAdjNode->val);
            Visited[OldAdjNode] = NewAdjNode;
            CopyNode->neighbors.push_back(NewAdjNode);
            NextQueue.push_back({OldAdjNode, NewAdjNode});
          } else {
            CopyNode->neighbors.push_back(Visited.at(OldAdjNode));
          }
        }
      }
      Queue.swap(NextQueue);
    }
    return CopyStart;
  }
};
