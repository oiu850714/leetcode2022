#include "headers.hpp"

class TwoSum {
public:
  TwoSum() {}

  void add(int Number) { HashTable_[Number]++; }

  bool find(int Value) const {
    for (auto [Num, Count] : HashTable_) {
      // By assumption, -2^31 <= Value <= 2^31 - 1, and -10^5 <= Num <= 10^5, so
      // Value - Num may not fit into int.
      int64_t Other = (int64_t)Value - Num;
      if (Other == Num) {
        if (Count > 1) {
          return true;
        }
      } else if (HashTable_.count(Other)) {
        return true;
      }
    }
    return false;
  }

private:
  // <Num, OccuredTimes>
  std::unordered_map<int, int> HashTable_;
};
