#include "headers.hpp"

class BrowserHistory {
public:
  BrowserHistory(std::string Homepage) : VisitHistroy_{std::move(Homepage)} {}

  void visit(std::string Url) {
    VisitHistroy_.erase(VisitHistroy_.begin() + CurrentStep_ + 1,
                        VisitHistroy_.end());
    VisitHistroy_.push_back(std::move(Url));
    CurrentStep_ = VisitHistroy_.size() - 1;
  }

  std::string back(int Steps) {
    CurrentStep_ = std::max(0, CurrentStep_ - Steps);
    return VisitHistroy_[CurrentStep_];
  }

  std::string forward(int Steps) {
    CurrentStep_ =
        std::min<int>(VisitHistroy_.size() - 1, CurrentStep_ + Steps);
    return VisitHistroy_[CurrentStep_];
  }

private:
  int CurrentStep_ = 0;
  std::vector<std::string> VisitHistroy_;
};
