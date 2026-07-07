#include "../leet.h"

class Solution {
public:
  int findPeakElement(std::vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (isPeak(nums, left)) {
        return left;
      } else if (isPeak(nums, right)) {
        return right;
      } else if (isPeak(nums, mid)) {
        return mid;
      }
      if (nums[mid] < nums[mid + 1]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
  bool isPeak(std::vector<int> &nums, int index) {
    if (index == nums.size() - 1 && index == 0) {
      return true;
    }
    if (index == nums.size() - 1 && nums[index] > nums[index - 1]) {
      return true;
    }
    if (index == 0 && nums[index] > nums[index + 1]) {
      return true;
    }
    if (index > 0 && index < nums.size() - 1 && nums[index] > nums[index + 1] &&
        nums[index] > nums[index - 1]) {
      return true;
    }
    return false;
  }
};
