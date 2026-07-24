#include "../leet.h"

class Solution {
public:
  int rob(std::vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    vector<int> dp(2);
    dp.back() = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int temp = dp.back();
      dp.back() = max(dp.back(), dp.front() + nums[i]);
      dp.front() = temp;
    }
    return dp.back();
  }
};
