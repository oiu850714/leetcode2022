#include "headers.hpp"

class Solution {
public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> &Image,
                                          int SR, int SC, int Color) {
    std::queue<std::pair<int, int>> Frontier;
    auto ModifiedImage = Image;
    auto SourceColor = Image[SR][SC];
    auto exploreImageAndEnqueue = [&ModifiedImage, &Image, Color,
                                   &Frontier](int Row, int Col) {
      ModifiedImage[Row][Col] = Color;
      // XXX: Hack, just use the original lvalue input to record exploration.
      Image[Row][Col] = -1;
      Frontier.push({Row, Col});
    };
    auto isValidRange = [&Image](int Row, int Col) {
      return Row >= 0 && Row < Image.size() && Col >= 0 &&
             Col < Image[0].size();
    };
    exploreImageAndEnqueue(SR, SC);
    while (!Frontier.empty()) {
      auto [Row, Col] = Frontier.front();
      Frontier.pop();
      // up, down, left, right
      std::vector<std::pair<int, int>> Directions{
          {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
      for (auto [RowDir, ColDir] : Directions) {
        auto NewRow = Row + RowDir, NewCol = Col + ColDir;
        if (isValidRange(NewRow, NewCol) &&
            ModifiedImage[NewRow][NewCol] == SourceColor &&
            Image[NewRow][NewCol] != -1) {
          exploreImageAndEnqueue(NewRow, NewCol);
        }
      }
    }
    return ModifiedImage;
  }
};