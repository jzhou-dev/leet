#include <vector>
using namespace std;

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>> &dungeon) {
    vector<vector<int>> dp(dungeon.size() + 1,
                           vector<int>(dungeon[0].size() + 1, INT_MAX));
    dp[dp.size() - 1][dp[0].size() - 2] = 1;
    dp[dp.size() - 2][dp[0].size() - 1] = 1;
    for (int i = dungeon.size() - 1; i >= 0; --i) {
      for (int j = dungeon[0].size() - 1; j >= 0; --j) {
        dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
      }
    }
    return dp[0][0];
  }
};
