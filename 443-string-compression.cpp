#include "headers.hpp"

class Solution {
public:
  int compress(std::vector<char> &Chars) {
    int CompressedEnd = 0, Curr = 1;
    int LastCharCount = 1;
    char LastChar = Chars[0];
    while (Curr <= Chars.size()) { // Use <= to include last component.
      if (Curr < Chars.size() && Chars[Curr] == LastChar) {
        LastCharCount++;
      } else {
        Chars[CompressedEnd++] = LastChar;
        if (LastCharCount > 1) {
          auto CountStr = std::to_string(LastCharCount);
          std::copy(CountStr.begin(), CountStr.end(),
                    Chars.begin() + CompressedEnd);
          CompressedEnd += CountStr.size();
        }
        if (Curr < Chars.size()) { // There's still some characters.
          LastChar = Chars[Curr];
          LastCharCount = 1;
        }
      }
      Curr++;
    }
    return CompressedEnd;
  }
};
