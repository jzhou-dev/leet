#include "../leet.h"

class Solution {
public:
  int maxSubarraySumCircular(std::vector<int> &nums) {
    int max = nums[0];
    int min = nums[0];
    int currMax = 0;
    int currMin = 0;
    int total = 0;
    for (int num : nums) {
      total += num;
      currMax = std::max(currMax + num, num);
      currMin = std::min(currMin + num, num);
      max = std::max(max, currMax);
      min = std::min(min, currMin);
    }
    return total == min ? max : std::max(max, total - min);
  }
};
