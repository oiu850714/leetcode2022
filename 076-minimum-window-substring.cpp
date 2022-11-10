#include "headers.hpp"

class Solution {
public:
  std::string minWindow(std::string S, std::string T) {
    if (S.size() < T.size()) {
      // Just impossible.
      return {};
    }

    auto Left = 0, Right = 0;
    auto MinWindowStart = -1,
         MinWindowLen = INT_MAX; // Store Start and Length of min window.
    auto CountT = getCharCount_(T);
    int Count = 0; // Count interval's characters that can be used to
                   // cover T.
    std::unordered_map<char, int> CountInterval;

    while (Right < S.size() || Count == T.size()) {
      if (Count != T.size()) {
        CountInterval[S[Right]]++;
        if (CountT.count(S[Right]) &&
            CountInterval.at(S[Right]) <= CountT.at(S[Right])) {
          Count++;
        }
        Right++;
      } else {
        if (Right - Left < MinWindowLen) {
          MinWindowLen = Right - Left;
          MinWindowStart = Left;
        }
        CountInterval[S[Left]]--;
        if (CountT.count(S[Left]) &&
            CountInterval.at(S[Left]) < CountT.at(S[Left])) {
          Count--;
        }
        Left++;
      }
    }
    return MinWindowStart != -1 ? S.substr(MinWindowStart, MinWindowLen) : "";
  }

private:
  std::unordered_map<char, int> getCharCount_(const std::string &S) {
    std::unordered_map<char, int> Ret;
    for (auto C : S) {
      Ret[C]++;
    }
    return Ret;
  }
};
