#include "../leet.h"

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    std::vector<std::vector<bool>> used(
        grid.size(), std::vector<bool>(grid[0].size(), false));
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (!used[i][j] && grid[i][j] == '1') {
          conquerIsland(grid, used, i, j);
          result++;
        }
      }
    }
    return result;
  }
  void conquerIsland(std::vector<std::vector<char>> &grid,
                     std::vector<std::vector<bool>> &used, int i, int j) {
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 ||
        used[i][j] || grid[i][j] == '0') {
      return;
    }
    used[i][j] = true;
    conquerIsland(grid, used, i + 1, j);
    conquerIsland(grid, used, i, j + 1);
    conquerIsland(grid, used, i - 1, j);
    conquerIsland(grid, used, i, j - 1);
  }
};
