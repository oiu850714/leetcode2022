#include "headers.hpp"

class Solution {
public:
  int shortestDistance(const std::vector<std::string> &Words, std::string W1,
                       std::string W2) {
    int Ret = Words.size();
    int MostRecentW1Idx = -1, MostRecentW2Idx = -1;
    for (int i = 0; i < Words.size(); i++) {
      if (Words[i] == W1) {
        MostRecentW1Idx = i;
      }
      if (Words[i] == W2) {
        MostRecentW2Idx = i;
      }
      // Both W1 and W2 have occrred
      // We will compute the distances of ALL ADJACENT W1 and W2, and store the
      // minimum of them in Ret.
      if (MostRecentW1Idx != -1 && MostRecentW2Idx != -1) {
        Ret = std::min(Ret, std::abs(MostRecentW1Idx - MostRecentW2Idx));
      }
    }
    return Ret;
  }
};
