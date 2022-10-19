#include "headers.hpp"

class Solution {
private:
  using RoutesTy = std::vector<std::vector<int>>;
  using RoutesAdjListTy = std::unordered_map<int, std::vector<int>>;
  using RoutesHashTy = std::unordered_map<int, std::unordered_set<int>>;

public:
  int numBusesToDestination(const RoutesTy &Routes, int Source, int Target) {
    if (Source == Target) {
      return 0;
    }

    // Assume Souce never be the Target.
    auto RouteAdjList = buildRoutesAdjList(Routes);
    RoutesHashTy RoutesStopFindingTable = buildRouteStopsFindingTable(Routes);
    auto Frontier(getInitialRoutes(Source, RoutesStopFindingTable));
    std::unordered_set<int> ExploredRoutes;

    while (!Frontier.empty()) {
      auto [Route, ChangedTimes] = Frontier.front();
      Frontier.pop();
      if (RoutesStopFindingTable[Route].count(Target)) {
        return ChangedTimes;
      }
      for (auto NewRoute : RouteAdjList[Route]) {
        if (!ExploredRoutes.count(NewRoute)) {
          Frontier.push({NewRoute, ChangedTimes + 1});
          ExploredRoutes.insert(NewRoute);
        }
      }
    }
    return -1;
  }

private:
  RoutesAdjListTy buildRoutesAdjList(const RoutesTy &Routes) {
    // First, calculate that, for every stop, which routes pass it.
    std::unordered_map<int, std::vector<int>> StopWithPassingRoutes;
    for (auto RouteIdx = 0; RouteIdx < Routes.size(); ++RouteIdx) {
      for (auto Stop : Routes[RouteIdx]) {
        StopWithPassingRoutes[Stop].push_back(RouteIdx);
      }
    }
    RoutesAdjListTy Ret;
    for (const auto &[Stop, PassingRoutes] : StopWithPassingRoutes) {
      if (PassingRoutes.size() >= 2) {
        // There are more than two routes passing at Stop.
        for (auto FirstRoute : PassingRoutes) {
          for (auto SecondRoute : PassingRoutes) {
            if (FirstRoute != SecondRoute) {
              Ret[FirstRoute].push_back(SecondRoute);
            }
          }
        }
      }
    }
    return Ret;
  }
  RoutesHashTy buildRouteStopsFindingTable(const RoutesTy &Routes) {
    RoutesHashTy Ret;
    for (auto RouteIdx = 0; RouteIdx < Routes.size(); RouteIdx++) {
      for (auto Stop : Routes[RouteIdx]) {
        Ret[RouteIdx].insert(Stop);
      }
    }
    return Ret;
  }
  // Route, ChangedTimes
  std::queue<std::pair<int, int>>
  getInitialRoutes(int Source, const RoutesHashTy &RoutesStopFindingTable) {
    std::queue<std::pair<int, int>> Ret;
    const int BFSLevel = 1;
    for (const auto &[Route, Stops] : RoutesStopFindingTable) {
      if (Stops.count(Source)) {
        Ret.push({Route, BFSLevel});
      }
    }
    return Ret;
  }
};
