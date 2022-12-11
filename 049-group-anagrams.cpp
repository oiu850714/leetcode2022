#include "headers.hpp"

class Solution {
  using GroupsTy = std::vector<std::vector<std::string>>;
  using GroupsMapTy = std::unordered_map<std::string, std::vector<std::string>>;

public:
  GroupsTy groupAnagrams(const std::vector<std::string> &Strs) {
    GroupsMapTy GroupsMap;
    for (const auto Str : Strs) {
      auto SortedStr = Str;
      // Since the length of each string of input is <= 100, sorting is really
      // fast.
      std::sort(SortedStr.begin(), SortedStr.end());
      GroupsMap[SortedStr].push_back(std::move(Str));
    }
    GroupsTy Groups;
    for (auto [_, Strs] : GroupsMap) {
      Groups.push_back(std::move(Strs));
    }
    return Groups;
  }
};
