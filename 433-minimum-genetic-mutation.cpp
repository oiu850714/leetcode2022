#include "headers.hpp"

class Solution {
public:
  int minMutation(std::string Start, std::string End,
                  std::vector<std::string> &Bank) {
    std::vector<std::string> OldQueue, NewQueue;
    std::unordered_set<std::string> Explored;
    OldQueue.push_back(Start);
    int Steps = 0;
    while (!OldQueue.empty()) {
      for (auto &S : OldQueue) {
        if (S == End) {
          return Steps;
        }
        for (auto &Gene : S) {
          auto OldGene = Gene;
          for (auto NewGene : {'A', 'T', 'C', 'G'}) {
            if (NewGene == OldGene) {
              continue;
            }
            Gene = NewGene;
            if (std::count(Bank.begin(), Bank.end(), S) && !Explored.count(S)) {
              NewQueue.push_back(S);
              Explored.insert(S);
            }
          }
          Gene = OldGene; // Restore.
        }
      }
      OldQueue = std::move(NewQueue);
      Steps += 1;
    }
    return -1;
  }
};
