#include "headers.hpp"

namespace leetcode {
static constexpr std::array _1To9{"",     "One", "Two",   "Three", "Four",
                                  "Five", "Six", "Seven", "Eight", "Nine"};
static constexpr std::array _10To19{
    "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
    "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
};
static constexpr std::array _203040nnn90{
    "" /* 0 */, "" /* 10*/, "Twenty",  "Thirty", "Forty",
    "Fifty",    "Sixty",    "Seventy", "Eighty", "Ninety"};
static constexpr std::array _100200300nnn900{
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
} // namespace leetcode

class Solution {
public:
  // Assume Num is nonnegative.
  std::string numberToWords(int Num) {
    // Num == 0 is really an edge case.
    if (Num == 0) {
      return "Zero";
    }

    std::vector<std::string> NonEmptyParts;
    for (auto UnitForEachThreeDigits :
         {"", // First three digits has no corresponding unit.
          " Thousand", " Million", " Billion"}) {
      auto ThreeDigits = Num % 1000;
      auto Word = threeDigitsToEng_(ThreeDigits);
      if (!Word.empty()) {
        Word += UnitForEachThreeDigits;
        NonEmptyParts.push_back(std::move(Word));
      }
      Num /= 1000;
      if (Num == 0) {
        break;
      }
    }
    std::reverse(NonEmptyParts.begin(), NonEmptyParts.end());

    // just equivalent to python string join.
    // Since Num initially is > 0, NonEmptyParts must have at least one element.
    std::string Ret{NonEmptyParts[0]};
    for (int i = 1; i < NonEmptyParts.size(); i++) {
      Ret += " " + NonEmptyParts[i];
    }

    return Ret;
  }

private:
  // Assume 0 <= ThreeDigits < 1000.
  std::string threeDigitsToEng_(int ThreeDigits) {
    if (ThreeDigits == 0) {
      return "";
    }
    if (ThreeDigits < 10) {
      return leetcode::_1To9[ThreeDigits];
    }
    if (ThreeDigits < 20) {
      return leetcode::_10To19[ThreeDigits - 10];
    }
    if (ThreeDigits < 100) {
      std::string SecondDigitWord = leetcode::_203040nnn90[ThreeDigits / 10];
      std::string FirstDigitWord = leetcode::_1To9[ThreeDigits % 10];
      return SecondDigitWord + (!FirstDigitWord.empty() ? " " : "") +
             FirstDigitWord;
    }

    std::string ThirdDigitWord =
        std::string(leetcode::_100200300nnn900[ThreeDigits / 100]) + " Hundred";
    std::string FirstTwoDigitsWord = threeDigitsToEng_(ThreeDigits % 100);
    return ThirdDigitWord + (!FirstTwoDigitsWord.empty() ? " " : "") +
           FirstTwoDigitsWord;
  }
};
