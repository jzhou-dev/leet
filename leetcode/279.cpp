using namespace std;
#include <vector>

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      int curr_sqr = 1;
      int min_sqrs = INT_MAX;
      while (i - (curr_sqr * curr_sqr) >= 0) {
        min_sqrs = min(min_sqrs, dp[i - (curr_sqr * curr_sqr)] + 1);
        curr_sqr++;
      }
      dp[i] = min_sqrs;
    }
    return dp.back();
  }
};
