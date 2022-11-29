#include "headers.hpp"

class Solution {
public:
  long long maxTaxiEarnings(int TotalLen,
                            std::vector<std::vector<int>> &Passengers) {
    // PassengerStartingAt[i] store all passengers reqeusting at point i,
    // and each element store the endpoint and earned dollar.
    // Note that no one will start at TotalLen and 0.
    std::vector<std::vector<std::pair<int, int>>> PassengerStartingAt(TotalLen);
    for (const auto &Passenger : Passengers) {
      auto Start = Passenger[0], End = Passenger[1];
      auto Dollar = End - Start + Passenger[2];
      PassengerStartingAt[Start].push_back({End, Dollar});
    }
    // Note that DPTable[TotalLen] is the base case.
    std::vector<long long> DPTable(TotalLen + 1);
    for (int Start = TotalLen - 1; Start >= 1; Start--) {
      // Case 1: do not carry passenger at Start, just go to Start + 1
      DPTable[Start] = DPTable[Start + 1];

      // Case 2: carry a passenger at Start.
      for (auto [End, Dollar] : PassengerStartingAt[Start]) {
        DPTable[Start] = std::max(DPTable[Start], Dollar + DPTable[End]);
      }
    }
    return DPTable[1];
  }
};
