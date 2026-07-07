#include "../leet.h"

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    int min = INT_MAX;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      min = std::min(min, nums[mid]);
      if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return min;
  }
};
