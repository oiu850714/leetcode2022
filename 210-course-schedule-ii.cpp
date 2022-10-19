#include "headers.hpp"

class Solution {
private:
  using PrerequisitesTy = std::vector<std::vector<int>>;
  using AdjListTy = std::vector<std::vector<int>>;

public:
  std::vector<int> findOrder(int NumCourses, PrerequisitesTy &Prerequisites) {
    if (canFinish(NumCourses, Prerequisites)) {
      return GlobalExploredNodesTopoOrder;
    }
    return {};
  }

private:
  // Adapt from 207.
  bool canFinish(int NumCourses, const PrerequisitesTy &Prerequisites) {
    auto AdjList = buildAdjList(NumCourses, Prerequisites);
    for (auto StartCourse = 0; StartCourse < NumCourses; ++StartCourse) {
      if (GlobalExploredNodes_.find(StartCourse) !=
          GlobalExploredNodes_.end()) {
        continue;
      }
      std::unordered_set<int> DFSExploredNodes;
      if (exploredCycle(StartCourse, AdjList, DFSExploredNodes)) {
        return false;
      }
    }
    return true;
  }

  AdjListTy buildAdjList(int NumCourses, const PrerequisitesTy &Prerequisites) {
    AdjListTy Ret(NumCourses);
    for (const auto &Prerequisite : Prerequisites) {
      Ret[Prerequisite[0]].push_back(Prerequisite[1]);
    }
    return Ret;
  }

  // DFSExploredNodes consists of the DFS "stack" of nodes, but O(1) for search.
  bool exploredCycle(int CurrCourse, const AdjListTy &AdjList,
                     std::unordered_set<int> &DFSExploredNodes) {
    GlobalExploredNodes_.insert(CurrCourse);
    DFSExploredNodes.insert(CurrCourse); // mark visited
    for (auto Prereq : AdjList[CurrCourse]) {
      if (DFSExploredNodes.find(Prereq) != DFSExploredNodes.end()) {
        // There is a cycle;
        return true;
      }
      if (GlobalExploredNodes_.find(Prereq) != GlobalExploredNodes_.end()) {
        continue;
      }
      if (exploredCycle(Prereq, AdjList, DFSExploredNodes)) {
        return true;
      }
    }
    DFSExploredNodes.erase(CurrCourse);
    // All prerequisites of CurrCourse have been added to the list, so
    // CurrCourse can also be added to the list.
    GlobalExploredNodesTopoOrder.push_back(CurrCourse);
    return false;
  }

  std::unordered_set<int> GlobalExploredNodes_;
  std::vector<int> GlobalExploredNodesTopoOrder;
};