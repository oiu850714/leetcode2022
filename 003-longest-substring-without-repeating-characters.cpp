#include "headers.hpp"

class Solution {
public:
  int lengthOfLongestSubstring(std::string S) {
    // Base case.
    if (S.empty()) {
      return 0;
    }

    // Store the index of each character of current substring.
    std::unordered_map<char, size_t> Table;
    int Start = 0;
    // Put first character in the table.
    Table[S[0]] = 0;
    size_t MaxLen = 1;
    // End is "enclusive" bound.
    for (size_t End = 1; End < S.size(); End++) {
      auto C = S[End];
      if (!Table.count(C)) {
        Table[C] = End;
        MaxLen = std::max(MaxLen, End - Start + 1);
      } else {
        auto OldIdxForC = Table[C];
        for (size_t i = Start; i <= OldIdxForC; i++) {
          Table.erase(S[i]);
        }
        Start = OldIdxForC + 1;
        Table[C] = End;
      }
    }
    return MaxLen;
  }
};