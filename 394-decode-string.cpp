#include "headers.hpp"

class Solution {
public:
  std::string decodeString(std::string S) {
    // Assume S is a valid encoded string.
    std::string Ret;
    for (auto Ch : S) {
      if (Ch != ']') {
        Ret.push_back(Ch);
      } else {
        int LastOpenBracketIdx = Ret.size() - 1;
        for (; LastOpenBracketIdx >= 0 && Ret[LastOpenBracketIdx] != '[';
             LastOpenBracketIdx--)
          ;
        // (Messy) Index calculation and pattern expansion.
        std::string CopyPattern = Ret.substr(LastOpenBracketIdx + 1);
        int CopyTime = 0;
        int CopyTimeIndex = LastOpenBracketIdx - 1;
        int Base = 1;
        while (CopyTimeIndex >= 0 && std::isdigit(Ret[CopyTimeIndex])) {
          CopyTime = CopyTime + (Ret[CopyTimeIndex--] - '0') * Base;
          Base *= 10;
        }
        // Remove the "k[encoded_string" in the Ret and start to expand the
        // pattern.
        Ret.erase(CopyTimeIndex + 1);
        while (CopyTime-- > 0) {
          Ret += CopyPattern;
        }
      }
    }
    return Ret;
  }
};