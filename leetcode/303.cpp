#include "../leet.h"

class NumArray {
public:
  std::vector<int> pre;
  NumArray(std::vector<int> &nums) {
    pre.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      pre.push_back(pre.back() + nums[i]);
    }
  }
  int sumRange(int left, int right) {
    return left == 0 ? pre[right] : pre[right] - pre[left - 1];
  }
};
