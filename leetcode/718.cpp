#include "../leet.h"

class Solution {
public:
  int findLength(std::vector<int> &nums1, std::vector<int> &nums2) {
    if (nums2.size() < nums1.size())
      return findLength(nums2, nums1);
    std::vector<std::vector<int>> dp(nums1.size() + 1,
                                     std::vector<int>(nums2.size() + 1, 0));
    int result = -1;
    for (int i = 1; i <= nums1.size(); ++i) {
      for (int j = 1; j <= nums2.size(); ++j) {
        if (nums1[i - 1] == nums2[j - #1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          result = std::max(dp[i][j], result);
        }
      }
    }
    return result;
  }
};
