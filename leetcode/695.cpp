#include "../leet.h"

class Solution {
public:
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<bool>> used(
        grid.size(), std::vector<bool>(grid[0].size(), false));
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] && !used[i][j]) {
          result = std::max(findArea(grid, used, i, j), result);
        }
      }
    }
    return result;
  }
  int findArea(std::vector<std::vector<int>> &grid,
               std::vector<std::vector<bool>> &used, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        !grid[i][j] || used[i][j]) {
      return 0;
    }
    used[i][j] = true;
    return 1 + findArea(grid, used, i + 1, j) + findArea(grid, used, i - 1, j) +
           findArea(grid, used, i, j - 1) + findArea(grid, used, i, j + 1);
  }
};
