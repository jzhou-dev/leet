#include "../leet.h"

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int index = 0;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      index = mid;
      if (nums[mid] == target) {
        break;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return index;
  }
};
