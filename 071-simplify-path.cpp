#include "headers.hpp"

class Solution {
public:
  std::string simplifyPath(std::string Path) {
    std::vector<std::string> Components;
    // The invariant is that i is always the index of some slash.
    for (size_t i = 0; i < Path.size();) {
      while (i + 1 < Path.size() && Path[i + 1] == '/') {
        // Next character is still a slash.
        i = i + 1;
      }
      if (i + 1 == Path.size()) {
        // i is on the trailing slash.
        // There are no more components to be parsed.
        break;
      }

      auto nextSlashPos = Path.find('/', i + 1);
      auto Component = Path.substr(i + 1, nextSlashPos - (i + 1));
      if (Component == ".") {
        // Current directory.
      } else if (Component == "..") {
        if (!Components.empty()) {
          // Go to parent directory.
          Components.pop_back();
        }
      } else {
        Components.push_back(Component);
      }
      i = nextSlashPos;
    }
    if (Components.size() == 0) {
      return "/";
    }
    std::string Ret;
    for (size_t i = 0; i < Components.size(); i++) {
      Ret += '/' + std::move(Components[i]);
    }
    return Ret;
  }
};
