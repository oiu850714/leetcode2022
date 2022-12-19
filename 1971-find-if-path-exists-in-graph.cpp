#include "headers.hpp"

class Solution {
  using EdgesTy = std::vector<std::vector<int>>;
  using AdjListTy = std::vector<std::vector<int>>;
  AdjListTy buildAdjList_(int NumNodes, const EdgesTy &Edges) {
    AdjListTy Ret(NumNodes);
    for (const auto &Edge : Edges) {
      // Bidirectional.
      Ret[Edge[0]].push_back(Edge[1]);
      Ret[Edge[1]].push_back(Edge[0]);
    }
    return Ret;
  }

public:
  bool validPath(int N, std::vector<std::vector<int>> &Edges, int Source,
                 int Destination) {
    auto AdjList = buildAdjList_(N, Edges);
    std::vector<int> Queue{Source};
    std::unordered_set<int> Visited{Source};
    while (!Queue.empty()) {
      std::vector<int> NextQueue;
      for (auto Node : Queue) {
        if (Node == Destination) {
          return true;
        }
        for (auto AdjNode : AdjList[Node]) {
          if (Visited.count(AdjNode)) {
            continue;
          }
          NextQueue.push_back(AdjNode);
          Visited.insert(AdjNode);
        }
      }
      Queue.swap(NextQueue);
    }
    return false;
  }
};
