#include "headers.hpp"

class Solution {
public:
  std::vector<int> asteroidCollision(std::vector<int> &Asteroids) {
    std::vector<int> Result;
    for (auto Asteroid : Asteroids) {
      if (Asteroid > 0) {
        Result.push_back(Asteroid);
      } else {
        // The asteroids collide only if the new asteroid goes left and the
        // last asteroid goes right.
        bool Destroyed = false;
        while (!Result.empty() && Result.back() > 0) {
          if (std::abs(Result.back()) > std::abs(Asteroid)) {
            Destroyed = true;
            break;
          } else if (std::abs(Result.back()) == std::abs(Asteroid)) {
            Destroyed = true;
            Result.pop_back();
            break;
          } else {
            Result.pop_back();
          }
        }
        if (!Destroyed) {
          Result.push_back(Asteroid);
        }
      }
    }
    return Result;
  }
};
