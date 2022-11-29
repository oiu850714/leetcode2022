#include "headers.hpp"

// <AdjNodeIdx, EdgeCost>.
using AdjListTy = std::vector<std::unordered_map<int, int>>;

class Solution {
private:
  auto makeHeapAndInitialPathCost_(const AdjListTy &AdjList, int Start) {
    // Store 1) shortest path cost 2) node
    std::vector<std::pair<int, int>> HeapArr;
    std::vector<int> InitialPathCosts(AdjList.size(),
                                      std::numeric_limits<int>::max());
    InitialPathCosts[Start] = 0;
    HeapArr.reserve(AdjList.size());
    // Note that the heap does not store the start node.
    for (int End = 0; End < AdjList.size(); End++) {
      if (End == Start) {
        continue;
      }
      int EdgeCost = std::numeric_limits<int>::max();
      if (AdjList[Start].count(End)) {
        // Start, End is adjacent
        EdgeCost = AdjList[Start].at(End);
        InitialPathCosts[End] = EdgeCost;
      }
      HeapArr.push_back({EdgeCost, End});
    }

    return std::pair{
        std::priority_queue{HeapArr.begin(), HeapArr.end(), std::greater()},
        InitialPathCosts};
  }

public:
  int networkDelayTime(std::vector<std::vector<int>> &Times, int N, int Start) {
    Start = Start - 1; // Convert to 0-based.
    auto AdjList = convert_(Times, N);

    auto [Heap, PathCosts] = makeHeapAndInitialPathCost_(AdjList, Start);
    std::unordered_set<int> NonVisited;
    for (int Node = 0; Node < N; Node++) {
      // Skip Start.
      if (Node != Start) {
        NonVisited.insert(Node);
      }
    }
    int DelayTime = 0;
    for (auto RemainNodes = N - 1; RemainNodes > 0; RemainNodes--) {
      int MinNode = -1, MinPathCost = std::numeric_limits<int>::max();
      for (std::tie(MinPathCost, MinNode) = Heap.top();
           !NonVisited.count(MinNode);) {
        // Use LAZY DELETETION.
        Heap.pop();
        std::tie(MinPathCost, MinNode) = Heap.top();
      }
      if (MinPathCost == std::numeric_limits<int>::max()) {
        // Remaining nodes cannot be reached from Start.
        return -1;
      }
      DelayTime = MinPathCost;
      NonVisited.erase(MinNode);
      for (auto [MinAdjNode, EdgeCost] : AdjList[MinNode]) {
        auto NewPathFromMin = MinPathCost + EdgeCost;
        if (!NonVisited.count(MinAdjNode) ||
            PathCosts[MinAdjNode] <= NewPathFromMin) {
          continue;
        }
        PathCosts[MinAdjNode] = NewPathFromMin;
        Heap.push({NewPathFromMin, MinAdjNode});
      }
    }
    return DelayTime;
  }

private:
  // Note that the node index of the holy input is 1-based.
  // We first convert it to 0-based; that does not affect the solution.
  AdjListTy convert_(std::vector<std::vector<int>> &Times, int N) {
    AdjListTy AdjList(N);
    for (const auto &Time : Times) {
      auto Start = Time[0] - 1, End = Time[1] - 1;
      auto Delay = Time[2];
      AdjList[Start][End] = Delay;
    }
    return AdjList;
  }
};
