#include "headers.hpp"

class Solution {
public:
  int maximalRectangle(std::vector<std::vector<char>> &Matrix) {
    std::vector<int> Histogram(Matrix[0].size());
    for (int i = 0; i < Histogram.size(); i++) {
      Histogram[i] = Matrix[0][i] == '0' ? 0 : 1;
    }

    int Ret = largestRectangleArea_(Histogram);
    for (int i = 1; i < Matrix.size(); i++) {
      auto NewHistogram = Histogram;
      for (int j = 0; j < Histogram.size(); j++) {
        if (Matrix[i][j] == '0') {
          NewHistogram[j] = 0;
        } else {
          NewHistogram[j]++;
        }
      }
      Histogram.swap(NewHistogram);
      Ret = std::max(Ret, largestRectangleArea_(Histogram));
    }
    return Ret;
  }

private:
  // Just reduce to 084.
  int largestRectangleArea_(std::vector<int> &Heights) {
    auto NextSmallerHeight = nextSmallerHeights_(Heights);
    auto PrevSmallerHeight = prevSmallerHeights_(Heights);

    int Ret = 0;
    for (int i = 0; i < Heights.size(); i++) {
      Ret = std::max(
          Ret, ((NextSmallerHeight[i] - i) + (i - PrevSmallerHeight[i]) - 1) *
                   Heights[i]);
    }
    return Ret;
  }

  std::vector<int> nextSmallerHeights_(const std::vector<int> &Heights) {
    std::vector<int> Ret(Heights.size(), Heights.size());

    std::stack<int> MonoStack;
    for (int i = 0; i < Heights.size(); i++) {
      while (!MonoStack.empty() && Heights[i] < Heights[MonoStack.top()]) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }

  std::vector<int> prevSmallerHeights_(const std::vector<int> &Heights) {
    std::vector<int> Ret(Heights.size(), -1);

    std::stack<int> MonoStack;
    for (int i = Heights.size() - 1; i >= 0; i--) {
      while (!MonoStack.empty() && Heights[i] < Heights[MonoStack.top()]) {
        Ret[MonoStack.top()] = i;
        MonoStack.pop();
      }
      MonoStack.push(i);
    }
    return Ret;
  }
};
