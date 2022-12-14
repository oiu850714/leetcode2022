#include "headers.hpp"

using namespace std::string_literals;

class Codec {
public:
  std::string encode(std::vector<std::string> &Strs) {
    std::string Ret;
    for (auto &Str : Strs) {
      Ret += Str + '\0';
    }
    return Ret;
  }

  std::vector<std::string> decode(std::string S) {
    std::vector<std::string> Ret;
    int Beg = 0;
    while (Beg < S.size()) {
      // Notice that we MUST use std::string literals.
      // If we just write "\0" instead of "\0"s, then it will be treated like
      // "empty string literal".
      // Refer to:
      // https://stackoverflow.com/questions/164168/how-do-you-construct-a-stdstring-with-an-embedded-null
      auto End = S.find_first_of("\0"s, Beg);
      Ret.push_back(S.substr(Beg, End));
      Beg = End + 1;
    }
    return Ret;
  }
};
