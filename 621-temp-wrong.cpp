#include "headers.hpp"

class Solution {
public:
  int leastInterval(std::vector<char> &Tasks, int IdleTime) {
    std::map<char, int> PerTaskCount;
    for (auto Task : Tasks) {
      PerTaskCount[Task]++;
    }
    auto TimeStamp = 0;
    for (auto NumRRTasks = getRoundRobinTasks(PerTaskCount); NumRRTasks != 0;) {
      auto RRIterations = getRoundRobinIterations(PerTaskCount);
      auto IdlePerIteration = std::max(IdleTime - NumRRTasks + 1, 0);
      TimeStamp +=
          (RRIterations * NumRRTasks) + RRIterations * IdlePerIteration;
      removeTasks(PerTaskCount);
      NumRRTasks = getRoundRobinTasks(PerTaskCount);
      if (NumRRTasks == 0 && IdlePerIteration > 0) {
        // If this is the last iteration, then we do not need to wait the last
        // idle time.
        TimeStamp -= IdlePerIteration;
      }
    }
    return TimeStamp;
  }

private:
  int getRoundRobinTasks(const std::map<char, int> &PerTaskCount) {
    return std::count_if(PerTaskCount.begin(), PerTaskCount.end(),
                         [](const auto &Task) { return Task.second != 0; });
  }
  int getRoundRobinIterations(const std::map<char, int> &PerTaskCount) {
    auto Min = 100000; // Use the assumption that the number of tasks <= 10^4.
    for (auto &[Task, Count] : PerTaskCount) {
      if (Count != 0) {
        Min = std::min(Min, Count);
      }
    }
    return Min;
  }
  void removeTasks(std::map<char, int> &PerTaskCount) {
    auto RemoveNumbers = getRoundRobinIterations(PerTaskCount);
    for (auto &[Task, Count] : PerTaskCount) {
      if (Count != 0) {
        Count -= RemoveNumbers;
      }
    }
  }
};