#include "headers.hpp"

class Solution {
public:
  int longestValidParentheses(std::string S) {
    auto ParenTable = buildOpenParanTable_(S);
    std::vector<int> DPTable(S.size() + 1);
    // Base case: no matter what S[0] is, a single '(' or ')' cannot be valid.
    DPTable[0] = 0;

    int MaxLen = 0;
    for (int i = 1; i < S.size(); ++i) {
      if (S[i] == '(') {
        // If S[i] is '(' then the longest valid paren ENDING AT S[i] is empty.
        DPTable[i] = 0;
        continue;
      }

      if (ParenTable[i] == -1) {
        // There is no matching open paren of this ')' at S[i].
        DPTable[i] = 0;
        continue;
      } else {
        DPTable[i] =
            (i - ParenTable[i] + 1) + // The length of the substring starting
                                      // from the matching paren to ')' at S[i]
            (ParenTable[i] == 0
                 ? 0
                 : DPTable[ParenTable[i] -
                           1]); // plus the longest valid paran ending at the
                                // index before the match open paren, IF ANY.
        MaxLen = std::max(MaxLen, DPTable[i]);
      }
    }
    return MaxLen;
  }

private:
  std::vector<int> buildOpenParanTable_(const std::string &S) {
    std::stack<std::pair<char, int>> Stack;
    std::vector<int> Ret(S.size());
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '(') {
        Ret[i] = -1;
        Stack.push({'(', i});
      } else {
        while (!Stack.empty() && Stack.top().first == ')') {
          Stack.pop();
        }
        if (Stack.empty()) {
          Ret[i] = -1;
        } else {
          Ret[i] = Stack.top().second;
          Stack.pop();
        }
      }
    }
    return Ret;
  }
};