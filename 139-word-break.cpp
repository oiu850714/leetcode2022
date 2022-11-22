#include "headers.hpp"

class Solution {
public:
  bool wordBreak(std::string S, std::vector<std::string> &Dict) {
    std::vector<bool> DPTable(S.size() + 1);

    // Base case.
    DPTable.front() = true; // Empty string can be "constructed" using ZERO
                            // words in the dictionary.

    for (int End = 1; End <= DPTable.size(); End++) {
      for (const auto &Word : Dict) {
        if (Word.size() > End) {
          continue;
        }

        // Word is a suffix of S[0, End).
        if (hasSuffixEndAtEnd_(S, End, Word) &&
            DPTable[End - Word.size()] == true) {
          DPTable[End] = true;
        }
      }
    }
    return DPTable.back();
  }

  // Assume S[0, End).size() >= Word.size().
  bool hasSuffixEndAtEnd_(const std::string &S, int End,
                          const std::string &Word) {
    return S.compare(End - Word.size(), Word.size(), Word) == 0;
  }
};
