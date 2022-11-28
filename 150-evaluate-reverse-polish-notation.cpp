#include "headers.hpp"
#include <functional>

class Solution {
public:
  int evalRPN(std::vector<std::string> &Tokens) {
    // long long to prevent overflow.
    std::stack<long long> Stack;
    std::unordered_map<std::string,
                       std::function<long long(long long, long long)>>
        Operators{
            {"+", std::plus{}},
            {"-", std::minus{}},
            {"*", std::multiplies{}},
            {"/", std::divides{}},
        };
    for (auto Token : Tokens) {
      if (!Operators.count(Token)) {
        Stack.push(std::stoi(Token));
      } else {
        // Note the order of Op1 and Op2 ARE important.
        auto Op2 = Stack.top();
        Stack.pop();
        auto Op1 = Stack.top();
        Stack.pop();
        Stack.push(Operators[Token](Op1, Op2));
      }
    }
    return Stack.top();
  }
};
