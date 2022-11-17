#include "headers.hpp"

class Solution {
public:
  std::vector<std::string> findRepeatedDnaSequences(std::string S) {
    if (S.size() < 10) {
      return {};
    }
    std::unordered_map<std::string, int> Seqs;
    for (int i = 0; i < S.size() - 9; i++) {
      auto NewSeq = S.substr(i, 10);
      Seqs[NewSeq]++;
    }
    std::vector<std::string> Ret;
    for (auto [Seq, Count] : Seqs) {
      if (Count > 1) {
        Ret.push_back(std::move(Seq));
      }
    }
    return Ret;
  }
};
