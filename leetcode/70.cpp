#include "../leet.h"

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0 || n == 1)
      return 1;
    vector<int> dp(2, 1);
    for (int i = 2; i <= n; ++i) {
      int temp = dp[1];
      dp[1] = dp[0] + temp;
      dp[0] = temp;
      cout << dp[1] << endl;
    }
    return dp.back();
  }
};
