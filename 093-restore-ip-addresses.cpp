#include "headers.hpp"

class Solution {
  using IPStrsTy = std::vector<std::string>;
  using ComponentsTy = std::vector<std::string>;

public:
  IPStrsTy restoreIpAddresses(std::string S) {
    S_ = std::move(S);
    ComponentsTy Components;
    backtrack_(0, Components);
    return std::move(Result_);
  }

private:
  std::string S_;
  IPStrsTy Result_;

  void backtrack_(int LastCompEnd, ComponentsTy &Components) {
    if (Components.size() == 4 && LastCompEnd == S_.size()) {
      Result_.push_back(toIP_(Components));
      return;
    }

    for (int i = LastCompEnd + 1; i <= S_.size(); i++) {
      auto Component = S_.substr(LastCompEnd, i - LastCompEnd);
      if (isValidComponent_(Component)) {
        Components.push_back(Component);
        backtrack_(i, Components);
        Components.pop_back();
      }
    }
  }

  std::string toIP_(const ComponentsTy &Components) const {
    return Components[0] + '.' + Components[1] + '.' + Components[2] + '.' +
           Components[3];
  }

  bool isValidComponent_(const std::string &Component) const noexcept {
    assert(!Component.empty());
    if (Component.size() == 1) {
      return true;
    }

    if (Component.size() == 2) {
      return Component[0] != '0';
    }

    if (Component.size() == 3) {
      return "100" <= Component && Component <= "255";
    }

    return false;
  }
};
