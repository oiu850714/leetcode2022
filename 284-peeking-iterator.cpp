#include "headers.hpp"

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.

class Iterator {
  struct Data;
  Data *data;

public:
  Iterator(const std::vector<int> &nums);
  Iterator(const Iterator &iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
public:
  PeekingIterator(const std::vector<int> &Nums)
      : Iterator(Nums), NextVal_(Iterator::next()),
        HasNextOfNext_(Iterator::hasNext()), HasNext_(true) {}

  int peek() { return NextVal_; }

  int next() {
    auto Ret = NextVal_;
    if (HasNextOfNext_) {
      NextVal_ = Iterator::next();
      HasNextOfNext_ = Iterator::hasNext();
    } else {
      HasNext_ = false;
    }
    return Ret;
  }

  bool hasNext() const { return HasNext_; }

private:
  int NextVal_;
  bool HasNextOfNext_;
  bool HasNext_;
};
