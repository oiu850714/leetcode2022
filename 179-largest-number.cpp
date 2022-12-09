#include "headers.hpp"

using namespace std::literals::string_literals;

class Solution {
public:
  std::string largestNumber(std::vector<int> &Nums) {
    // Well, input may be [0, 0, 0, 0, 0].
    if (std::all_of(Nums.begin(), Nums.end(),
                    [](auto Num) { return Num == 0; })) {
      return "0";
    }
    std::vector<std::string> NumStrs;
    for (auto Num : Nums) {
      NumStrs.push_back(std::to_string(Num));
    }
    std::sort(NumStrs.begin(), NumStrs.end(),
              [](const std::string &S1, const std::string &S2) {
                return S1 + S2 > S2 + S1;
              });
    return std::accumulate(NumStrs.begin(), NumStrs.end(), ""s);
  }
};
