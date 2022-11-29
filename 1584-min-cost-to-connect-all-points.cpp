#include "headers.hpp"

class Solution {
private:
  int manDist_(const std::vector<std::vector<int>> &Points, int Beg, int End) {
    return std::abs(Points[Beg][0] - Points[End][0]) +
           std::abs(Points[Beg][1] - Points[End][1]);
  }
  // Assume the algo starts at the 0th-point.
  auto makeHeapAndInitialCost_(const std::vector<std::vector<int>> &Points) {
    // Store 1) cost 2) point
    std::vector<std::pair<int, int>> HeapArr;
    std::vector<int> PointInitialCosts(Points.size(),
                                       std::numeric_limits<int>::max());
    PointInitialCosts[0] = 0;

    // Node that the heap does not store the 0th node.
    for (int End = 1; End < Points.size(); End++) {
      auto Cost = manDist_(Points, 0, End);
      HeapArr.push_back({Cost, End});
      PointInitialCosts[End] = Cost;
    }

    return std::pair{
        std::priority_queue{HeapArr.begin(), HeapArr.end(), std::greater()},
        PointInitialCosts};
  }

public:
  int minCostConnectPoints(const std::vector<std::vector<int>> &Points) {
    int NumNodes = Points.size();
    int TotalCost = 0;
    std::unordered_set<int> NonVisited;
    for (int i = 1; i < NumNodes; i++) { // Skip starting point, i.e. 0th point.
      NonVisited.insert(i);
    }

    auto [Heap, CurrPointCosts] = makeHeapAndInitialCost_(Points);
    // Note that we only need to find another NumNodes - 1 points, since we have
    // added the 0th point.
    for (auto RemainNodes = NumNodes - 1; RemainNodes > 0; RemainNodes--) {
      int ClosestPoint = -1, Cost = -1;
      for (std::tie(Cost, ClosestPoint) = Heap.top();
           !NonVisited.count(ClosestPoint);) {
        // Use LAZY DELETETION.
        Heap.pop();
        std::tie(Cost, ClosestPoint) = Heap.top();
      }
      TotalCost += Cost;
      NonVisited.erase(ClosestPoint);
      CurrPointCosts[ClosestPoint] = 0;
      for (int Point = 0; Point < NumNodes; Point++) {
        if (Point == ClosestPoint || !NonVisited.count(Point)) {
          continue;
        }
        auto NewCost = manDist_(Points, ClosestPoint, Point);
        if (NewCost < CurrPointCosts[Point]) {
          CurrPointCosts[Point] = NewCost;
          // We do NOT delete {OldCost, Point} right now; use LAZY DELETETION
          // instead. (This is because std::priority_queue has no delete or
          // decrease key operations.) See:
          // https://stackoverflow.com/questions/9209323/easiest-way-of-using-min-priority-queue-with-key-update-in-c
          Heap.push({NewCost, Point});
        }
      }
    }
    return TotalCost;
  }
};
