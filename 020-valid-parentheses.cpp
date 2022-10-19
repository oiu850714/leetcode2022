#include "headers.hpp"

class Solution {
public:
  bool isValid(std::string Input) {
    // Assume Input only contains parentheses.
    std::stack<char> Stack;

    for (auto C : Input) {
      // If C is a opening parenthesis.
      if (isOpenParen(C)) {
        Stack.push(C);
        continue;
      }
      // Otherwise, C is a closed parenthesis.

      if (Stack.empty()) {
        // There is no more character to match.
        return false;
      }
      if (!isMatch(Stack.top(), C)) {
        // Stack is nonempty but the char at the top is a mismatched opening
        // parenthesis.
        return false;
      }

      // Else, pop the matched parenthesis.
      Stack.pop();
    }

    // If Stack still contains some parentheses to be matched when the whole
    // Input is scanned, then Input is invalid.
    return Stack.empty();
  }

  bool isOpenParen(char C) { return C == '(' || C == '[' || C == '{'; }

  bool isMatch(char Open, char Close) {
    return (Open == '(' && Close == ')') || (Open == '{' && Close == '}') ||
           (Open == '[' && Close == ']');
  }
};
