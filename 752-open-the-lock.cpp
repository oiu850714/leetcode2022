#include "headers.hpp"

class Solution {
public:
  int openLock(std::vector<std::string> &Deadends, std::string Target) {
    if (std::count(Deadends.begin(), Deadends.end(), "0000")) {
      // An untold pitty test case.
      return -1;
    }

    // The Deadends can be size 500, so convert it to hash table.
    std::unordered_set<std::string> DeadendsMap(Deadends.begin(),
                                                Deadends.end());
    std::vector<std::string> OldQueue, NewQueue;
    std::unordered_set<std::string> Explored;
    OldQueue.push_back("0000");
    int Steps = 0;
    auto Increment = [](auto Digit) {
      return (Digit + 1) <= '9' ? Digit + 1 : '0';
    };
    auto Decrement = [](auto Digit) {
      return (Digit - 1) >= '0' ? Digit - 1 : '9';
    };
    while (!OldQueue.empty()) {
      for (auto &Code : OldQueue) {
        if (Code == Target) {
          return Steps;
        }
        for (auto &Digit : Code) {
          auto OldDigit = Digit;
          for (auto NewDigit : {Increment(OldDigit), Decrement(OldDigit)}) {
            Digit = NewDigit;
            if (!DeadendsMap.count(Code) && !Explored.count(Code)) {
              NewQueue.push_back(Code);
              Explored.insert(Code);
            }
          }
          Digit = OldDigit; // Restore digit.
        }
      }
      OldQueue = std::move(NewQueue);
      Steps += 1;
    }
    return -1;
  }
};
