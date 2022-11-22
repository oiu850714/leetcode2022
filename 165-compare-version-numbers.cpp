#include "headers.hpp"

class Solution {
public:
  int compareVersion(std::string V1, std::string V2) {
    std::vector<int> V1Components(toIntComponents_(V1)),
        V2Components(toIntComponents_(V2));
    for (int i = 0; i < V1Components.size() && i < V2Components.size(); i++) {
      if (V1Components[i] < V2Components[i]) {
        return -1;
      }
      if (V1Components[i] > V2Components[i]) {
        return 1;
      }
    }

    // For the sake of handling the case like "1.0" == "1.0.0.0.0".
    if (V1Components.size() == V2Components.size()) {
      return 0;
    } else if (V1Components.size() > V2Components.size()) {
      for (int i = V2Components.size(); i < V1Components.size(); i++) {
        if (V1Components[i] != 0) {
          return 1;
        }
      }
      return 0;
    } else {
      for (int i = V1Components.size(); i < V2Components.size(); i++) {
        if (V2Components[i] != 0) {
          return -1;
        }
      }
      return 0;
    }
  }

  std::vector<int> toIntComponents_(std::string S) {
    std::vector<int> Ret;
    for (size_t i = 0, dot_pos = S.find('.', i);;) {
      Ret.push_back(std::stoi(S.substr(i, dot_pos - i)));

      // We have found the last component.
      if (dot_pos == std::string::npos) {
        break;
      }

      i = dot_pos + 1;
      dot_pos = S.find('.', i);
    }
    return Ret;
  }
};
