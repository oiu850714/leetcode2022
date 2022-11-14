#include "headers.hpp"

class CombinationIterator {
  constexpr static int nChoosek(unsigned n, unsigned k) {
    if (k > n)
      return 0;
    if (k * 2 > n)
      k = n - k;
    if (k == 0)
      return 1;

    int result = n;
    for (int i = 2; i <= k; ++i) {
      result *= (n - i + 1);
      result /= i;
    }
    return result;
  }

public:
  CombinationIterator(std::string Chars, int SubsetSize)
      : Chars_{std::move(Chars)}, KIndices_(SubsetSize),
        Counter_(nChoosek(Chars_.size(), SubsetSize)) {
    for (int k = 0; k < KIndices_.size(); k++) {
      KIndices_[k] = k;
    }
  }

  std::string next() {
    auto Ret = convertIndicesToCombination_();
    updateIndices_();
    Counter_--;
    return Ret;
  }

  bool hasNext() const { return Counter_ > 0; }

private:
  std::string Chars_;
  std::vector<int> KIndices_;
  int Counter_;

  std::string convertIndicesToCombination_() const {
    std::string Ret;
    for (auto Idx : KIndices_) {
      Ret.push_back(Chars_[Idx]);
    }
    return Ret;
  }

  void updateIndices_() {
    // Just simulate index updating logic for k-dimensional for-loop that only
    // counter indices without duplicates.
    // e.g. for 3-dimenional loop:
    // {0, 1, 2} -> {0, 1, 3} -> ... -> "{0, 1, n - 1} -> {0, 2, 3}" ->
    // {0, 2, 4} -> ... -> "{0, n - 2, n - 1} -> {1, 2, 3}" -> ... ->
    // "{1, n - 2, n - 1} -> {2, 3, 4}" -> ... -> {n - 3, n- 2, n - 1}.
    // The quotes parts is the case with multiple indices updated.
    for (int k = KIndices_.size() - 1, CharsIdx = Chars_.size() - 1; k >= 0;
         k--, CharsIdx--) {
      if (KIndices_[k] == CharsIdx) {
        continue;
      } else {
        KIndices_[k]++;
        for (int j = 1; j + k < KIndices_.size(); j++) {
          KIndices_[k + j] = KIndices_[k] + j;
        }
        break;
      }
    }
  }
};
