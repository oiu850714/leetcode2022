#include "headers.hpp"

using AdjListTy = std::unordered_map<int, std::vector<int>>;
using CoordinateTy = std::unordered_map<int, std::vector<int>>;

class Solution {
public:
  int removeStones(std::vector<std::vector<int>> &Stones) {
    CoordinateTy XaxisStones, YaxisStones;
    for (int StoneIdx = 0; StoneIdx < Stones.size(); StoneIdx++) {
      auto Coordinate = Stones[StoneIdx];
      XaxisStones[Coordinate[0]].push_back(StoneIdx);
      YaxisStones[Coordinate[1]].push_back(StoneIdx);
    }

    auto AdjList = buildAdjListFromCoords(XaxisStones, YaxisStones, Stones);
    return findMaximumCC(AdjList);
  }

private:
  AdjListTy
  buildAdjListFromCoords(const CoordinateTy &XCoor, const CoordinateTy &YCoor,
                         const std::vector<std::vector<int>> &Stones) {
    AdjListTy Ret;
    for (auto StoneIdx = 0; StoneIdx < Stones.size(); StoneIdx++) {
      Ret[StoneIdx] = {};
    }
    for (int StoneIdx = 0; StoneIdx < Stones.size(); StoneIdx++) {
      auto StoneX = Stones[StoneIdx][0], StoneY = Stones[StoneIdx][1];
      // Warning: some coordinates between 0 and 10000 may NOT exist in XCoor
      // and YCoor. Allocating 10001 vectors for all possible coordinates seems
      // very slow at leetcode runtime, so we check whether the coordinate
      // exists instead.
      if (XCoor.count(StoneX)) {
        for (const auto SameXStone : XCoor.at(StoneX)) {
          Ret[StoneIdx].push_back(SameXStone);
        }
      }
      if (YCoor.count(StoneY)) {
        for (const auto SameYStone : YCoor.at(StoneY)) {
          Ret[StoneIdx].push_back(SameYStone);
        }
      }
    }
    return Ret;
  }

  // Modified from 547.
  // Assume the number of nodes is equal to the size of AdjList.
  int findMaximumCC(const AdjListTy &AdjList) {
    int Ret = 0;
    std::vector<int> VisitedStone(AdjList.size());
    for (int Stone = 0; Stone < AdjList.size(); Stone++) {
      if (!VisitedStone[Stone]) {
        // Note that, by the description of the problem, one of stones of the CC
        // is NOT removed. So we need to subtract 1 from the number of nodes of
        // the new CC just discovered.
        Ret += BFS(AdjList, Stone, VisitedStone) - 1;
      }
    }
    return Ret;
  }

  // Return the number of nodes in the corresponding CC of StartNode.
  int BFS(const AdjListTy &AdjList, int StartNode,
          std::vector<int> &VisitedStone) {
    std::vector<int> OldQueue, NewQueue;
    VisitedStone[StartNode] = 1;
    OldQueue.push_back(StartNode);
    int Ret = 1;
    while (!OldQueue.empty()) {
      for (auto StartNode : OldQueue) {
        for (auto EndNode : AdjList.at(StartNode)) {
          if (!VisitedStone[EndNode]) {
            VisitedStone[EndNode] = 1;
            NewQueue.push_back(EndNode);
          }
        }
      }
      Ret += NewQueue.size();
      OldQueue = std::move(NewQueue);
    }
    return Ret;
  }
};