#include "headers.hpp"

class Solution {
public:
  std::vector<int> nextGreaterElements(std::vector<int> &Nums) {
    std::vector<int> Ret(Nums.size(), -1);
    std::stack<int> MonoStackButStoreIdx;
    // Notice the number of iterations is doubled.
    for (int i = 0; i < Nums.size() * 2; i++) {
      auto WrappedIdx = i % Nums.size();
      if (MonoStackButStoreIdx.empty()) {
        MonoStackButStoreIdx.push(WrappedIdx);
        continue;
      }

      if (Nums[WrappedIdx] <= Nums[MonoStackButStoreIdx.top()]) {
        MonoStackButStoreIdx.push(WrappedIdx);
      } else {
        while (!MonoStackButStoreIdx.empty() &&
               Nums[MonoStackButStoreIdx.top()] < Nums[WrappedIdx]) {
          Ret[MonoStackButStoreIdx.top()] = Nums[WrappedIdx];
          MonoStackButStoreIdx.pop();
        }
        MonoStackButStoreIdx.push(WrappedIdx);
      }
    }
    return Ret;
  }
};
