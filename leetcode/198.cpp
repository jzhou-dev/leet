#include "../leet.h"

class Solution {
public:
  int rob(std::vector<int> &nums) {
    std::vector<int> store(nums.size() + 1);
    store[0] = 0;
    store[1] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      store[i + 1] = std::max(store[i], nums[i] + store[i - 1]);
    }
    return store.back();
  }
};
