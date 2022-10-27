#include "headers.hpp"

using AdjMatrix = std::vector<std::vector<int>>;

class Solution {
public:
  // why called "circle num"?
  int findCircleNum(AdjMatrix &IsConnected) {
    int Ret = 0;
    std::vector<int> VisitedCity(IsConnected.size());
    for (int City = 0; City < IsConnected.size(); City++) {
      if (!VisitedCity[City]) {
        Ret++;
        BFS(IsConnected, City, VisitedCity);
      }
    }
    return Ret;
  }

private:
  void BFS(const AdjMatrix &IsConnected, int StartCity,
           std::vector<int> &VisitedCity) {
    std::vector<int> OldQueue, NewQueue;
    VisitedCity[StartCity] = 1;
    OldQueue.push_back(StartCity);
    while (!OldQueue.empty()) {
      for (auto City : OldQueue) {
        for (int j = 0; j < IsConnected[City].size(); j++) {
          if (IsConnected[City][j] && !VisitedCity[j]) {
            VisitedCity[j] = 1;
            NewQueue.push_back(j);
          }
        }
      }
      OldQueue = std::move(NewQueue);
    }
  }
};