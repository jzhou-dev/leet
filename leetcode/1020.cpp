#include "../leet.h"

class Solution {
public:
  int numEnclaves(std::vector<std::vector<int>> &grid) {
    std::vector<std::vector<bool>> used(
        grid.size(), std::vector<bool>(grid[0].size(), false));
    int result = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        int num = 0;
        if (grid[i][j] && validEnclave(grid, used, i, j, num)) {
          result += num;
        }
      }
    }
    return result;
  }
  bool validEnclave(std::vector<std::vector<int>> &grid,
                    std::vector<std::vector<bool>> &used, int i, int j,
                    int &num) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return false;
    }
    if (!grid[i][j] || used[i][j]) {
      return true;
    }
    used[i][j] = true;
    num++;
    bool up = validEnclave(grid, used, i + 1, j, num);
    bool down = validEnclave(grid, used, i - 1, j, num);
    bool left = validEnclave(grid, used, i, j - 1, num);
    bool right = validEnclave(grid, used, i, j + 1, num);
    return up && down && left && right;
  }
};
