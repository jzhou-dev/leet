#include "../leet.h"

class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q(
        nums.begin(), nums.begin() + k);
    for (int i = k; i < nums.size(); ++i) {
      if (nums[i] > q.top()) {
        q.pop();
        q.push(nums[i]);
      }
    }
    return q.top();
  }
};
