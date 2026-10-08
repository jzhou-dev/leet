#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    if (amount == 0)
      return 0;
    vector<int> dp(amount + 1, 0);
    for (int i = 0; i < coins.size(); ++i) {
      if (coins[i] < amount + 1) {
        dp[coins[i]] = 1;
      }
    }
    for (int i = 1; i <= amount; ++i) {
      int curr_min = INT_MAX;
      for (int j = 0; j < coins.size(); ++j) {
        if (i - coins[j] >= 0 && (dp[i - coins[j]] != 0 || i - coins[j] == 0)) {
          curr_min = min(curr_min, dp[i - coins[j]] + 1);
        }
        if (curr_min != INT_MAX) {
          dp[i] = curr_min;
        }
      }
    }
    for (auto i : dp) {
      cout << i << ' ';
    }
    return dp.back() == 0 ? -1 : dp.back();
  }
};
