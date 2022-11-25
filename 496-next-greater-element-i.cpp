#include "headers.hpp"

class Solution {
public:
  std::vector<int> nextGreaterElement(std::vector<int> &Nums1,
                                      std::vector<int> &Nums2) {
    // Monotonically decreasing.
    std::stack<int> MonoStack;
    // Next Greater Element map.
    std::unordered_map<int, int> NGEMap;

    for (int i = 0; i < Nums2.size(); i++) {
      if (MonoStack.empty()) {
        MonoStack.push(Nums2[i]);
        continue;
      }

      if (Nums2[i] <= MonoStack.top()) {
        MonoStack.push(Nums2[i]);
      } else {
        while (!MonoStack.empty() && Nums2[i] > MonoStack.top()) {
          NGEMap.insert({MonoStack.top(), Nums2[i]});
          MonoStack.pop();
        }
        MonoStack.push(Nums2[i]);
      }
    };
    while (!MonoStack.empty()) {
      NGEMap.insert({MonoStack.top(), -1});
      MonoStack.pop();
    }

    std::vector<int> Ret;
    for (auto Num : Nums1) {
      Ret.push_back(NGEMap.at(Num));
    }
    return Ret;
  }
};
