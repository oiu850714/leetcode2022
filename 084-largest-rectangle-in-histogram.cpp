#include "headers.hpp"

class Solution {
public:
  int largestRectangleArea(std::vector<int> &Heights) {
    // The thought is use next smaller element.
    // NSEIdx(PSEIdx) = Next(Previous) Small Element Indices.
    // Default value represents the case that there is no smaller element
    // after(before) NSEIdx[i](PSEIdx[i]).
    std::vector<int> NSEIdx(Heights.size(), Heights.size());
    std::vector<int> PSEIdx(Heights.size(), -1);

    // Calculare NSEIdx and PSEIdx
    std::stack<int> Stack;
    for (size_t i = 0; i < Heights.size(); i++) {
      while (!Stack.empty() && Heights[Stack.top()] > Heights[i]) {
        NSEIdx[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }
    Stack = {}; // Clear
    for (size_t i = Heights.size() - 1; i != -1; i--) {
      while (!Stack.empty() && Heights[Stack.top()] > Heights[i]) {
        PSEIdx[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }

    // For each bar, we calculate the rectangle that:
    // 1. contains this bar,
    // 2. has the height as this bar.
    int MaxArea = 0;
    for (size_t i = 0; i < Heights.size(); i++) {
      // Note that we subtract 1 from the "width".
      auto AreaForBarI = Heights[i] * (NSEIdx[i] - PSEIdx[i] - 1);
      MaxArea = std::max(MaxArea, AreaForBarI);
    }
    return MaxArea;
  }
};
