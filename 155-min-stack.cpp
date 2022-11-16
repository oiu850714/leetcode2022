#include "headers.hpp"

class MinStack {
public:
  MinStack() {}

  void push(int Value) {
    int NewMin = StackWithMin_.empty()
                     ? Value
                     : std::min(Value, StackWithMin_.top().second);
    StackWithMin_.push({Value, NewMin});
  }

  void pop() { StackWithMin_.pop(); }

  int top() { return StackWithMin_.top().first; }

  int getMin() { return StackWithMin_.top().second; }

  // Each entry stores:
  // (1) Element
  // (2) Correponding Min of all elements below the element.
  std::stack<std::pair<int, int>> StackWithMin_;
};
