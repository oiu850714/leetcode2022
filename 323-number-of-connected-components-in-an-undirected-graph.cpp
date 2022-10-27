#include "headers.hpp"

using AdjListTy = std::unordered_map<int, std::vector<int>>;

class Solution {
public:
  int countComponents(int N, std::vector<std::vector<int>> &Edges) {
    AdjListTy AdjList;
    for (int i = 0; i < N; ++i) {
      // Just make sure that every node has corresponding (maybe empty) edge
      // list.
      AdjList[i] = {};
    }
    for (const auto &Edge : Edges) {
      // Note that the graph is undirected.
      AdjList[Edge[0]].push_back(Edge[1]);
      AdjList[Edge[1]].push_back(Edge[0]);
    }
    return findNumCC(AdjList);
  }

private:
  // Modified from 547.
  // Assume the number of nodes is equal to the size of AdjList.
  int findNumCC(const AdjListTy &AdjList) {
    int Ret = 0;
    std::vector<int> VisitedNode(AdjList.size());
    for (int Node = 0; Node < AdjList.size(); Node++) {
      if (!VisitedNode[Node]) {
        Ret++;
        BFS(AdjList, Node, VisitedNode);
      }
    }
    return Ret;
  }

  void BFS(const AdjListTy &AdjList, int StartNode,
           std::vector<int> &VisitedNode) {
    std::vector<int> OldQueue, NewQueue;
    VisitedNode[StartNode] = 1;
    OldQueue.push_back(StartNode);
    while (!OldQueue.empty()) {
      for (auto StartNode : OldQueue) {
        for (auto EndNode : AdjList.at(StartNode)) {
          if (!VisitedNode[EndNode]) {
            VisitedNode[EndNode] = 1;
            NewQueue.push_back(EndNode);
          }
        }
      }
      OldQueue = std::move(NewQueue);
    }
  }
};