#include "headers.hpp"

class Solution {
public:
  std::string getHint(std::string Secret, std::string Guess) {
    int Bulls = 0, Cows = 0;
    // Hashtable that stores each digit's count that "is not" a Bulls count.
    std::vector<int> ScrtDigitNonBullsCount(10);
    for (auto i = 0; i < Secret.size(); i++) {
      if (Secret[i] != Guess[i]) {
        ScrtDigitNonBullsCount[Secret[i] - '0'] += 1;
      }
    }

    for (auto i = 0; i < Guess.size(); i++) {
      if (Guess[i] == Secret[i]) {
        Bulls += 1;
        continue;
      }
      if (ScrtDigitNonBullsCount[Guess[i] - '0'] == 0) {
        // The i-th digit in Guess does not exist in Secret.
        continue;
      }
      // There is at least one Guess[i] digit in Secret.
      ScrtDigitNonBullsCount[Guess[i] - '0'] -= 1;
      Cows += 1;
    }
    return std::to_string(Bulls) + "A" + std::to_string(Cows) + "B";
  }
};