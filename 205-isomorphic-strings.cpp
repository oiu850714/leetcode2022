#include "headers.hpp"

class Solution {
public:
  bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::map<char, char> Map;
    std::map<char, char> InverseMap;
    for (auto Idx = 0u; Idx < s.size(); Idx++) {
      if (Map.find(s[Idx]) == Map.end()) {
        Map.emplace(s[Idx], t[Idx]);
      } else if (Map.at(s[Idx]) != t[Idx]) {
        return false;
      }

      if (InverseMap.find(t[Idx]) == InverseMap.end()) {
        InverseMap.emplace(t[Idx], s[Idx]);
      } else if (InverseMap.at(t[Idx]) != s[Idx]) {
        return false;
      }
    }
    return true;
  }
};