#include "headers.hpp"

class MinStack {
public:
  MinStack() {}

  void push(int Value) {
    auto It = Values_.insert(Value);
    IterStack_.push(It);
  }

  void pop() {
    auto Top = IterStack_.top();
    IterStack_.pop();
    Values_.erase(Top);
  }

  int top() { return *IterStack_.top(); }

  int getMin() { return *Values_.begin(); }

  std::multiset<int> Values_;
  std::stack<std::multiset<int>::iterator> IterStack_;
};
