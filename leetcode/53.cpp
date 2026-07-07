#include "../leet.h"

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int sum = 0;
    int max = INT_MIN;
    for (int num : nums) {
      sum += num;
      max = std::max(sum, max);
      if (sum < 0)
        sum = 0;
    }
    return max;
  }
};
