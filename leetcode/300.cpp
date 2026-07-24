#include "../leet.h"

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size() + 1, 1);
    int result = 0;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i + 1] = max(dp[j + 1] + 1, dp[i + 1]);
        }
      }
      result = max(result, dp[i + 1]);
    }
    return result;
  }
};
