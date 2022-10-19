#include "headers.hpp"

class Solution {
public:
  std::vector<int> findAnagrams(std::string S, std::string P) {
    if (S.size() < P.size()) {
      // Boring edge case that S is shorter than P.
      return {};
    }

    // Using the assumption that S and P only contain lowercase English letters.
    // We only need to construct a char-count hash table for P and (substring
    // of) S.
    std::vector<int> PCharCount(26);
    std::vector<int> SubSCharCount(26);
    for (auto PLetter : P) {
      PCharCount[PLetter - 'a'] += 1;
    }
    for (int i = 0; i < P.size(); i++) {
      SubSCharCount[S[i] - 'a'] += 1;
    }

    std::vector<int> Ret;
    bool lastSubstringIsAnagram = PCharCount == SubSCharCount;
    if (lastSubstringIsAnagram) {
      Ret.push_back(0);
    }

    // Be careful about the +1 offset of the last valid index.
    auto LastValidIndexOfS = S.size() - P.size() + 1;
    for (int i = 1; i < LastValidIndexOfS; i++) {
      if (!lastSubstringIsAnagram) {
        if (S[i - 1] == S[i + P.size() - 1]) {
          // In this case we don't need to modify the char count hash table for
          // S, and the (new) substring of S is still not an anagram.
          continue;
        }
        SubSCharCount[S[i - 1] - 'a'] -= 1;
        SubSCharCount[S[i + P.size() - 1] - 'a'] += 1;
        if (PCharCount == SubSCharCount) {
          Ret.push_back(i);
          lastSubstringIsAnagram = true;
        }
      } else {
        if (S[i - 1] == S[i + P.size() - 1]) {
          // In this case we don't need to modify the char count hash table for
          // S, and the (new) substring of S is still an anagram.
          Ret.push_back(i);
        } else {
          SubSCharCount[S[i - 1] - 'a'] -= 1;
          SubSCharCount[S[i + P.size() - 1] - 'a'] += 1;
          // If the new character is different from the old (removed) character,
          // then the char count hash table must be different.
          lastSubstringIsAnagram = false;
        }
      }
    }
    return Ret;
  }
};