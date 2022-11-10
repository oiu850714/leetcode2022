#include "headers.hpp"

class MyQueue {
public:
  void push(int X) { S1_.push(X); }

  // Assume Queue nonempty.
  int pop() {
    FillS2IfEmpty_();
    auto Ret = S2_.top();
    S2_.pop();
    return Ret;
  }

  // Assume Queue nonempty.
  int peek() {
    FillS2IfEmpty_();
    return S2_.top();
  }

  bool empty() { return S1_.empty() && S2_.empty(); }

private:
  std::stack<int> S1_, S2_;

  void FillS2IfEmpty_() {
    if (S2_.empty()) {
      while (!S1_.empty()) {
        auto Top = S1_.top();
        S1_.pop();
        S2_.push(Top);
      }
    }
  }
};
