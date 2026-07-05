#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    std::vector<bool> used(nums.size(), false);
    permute(result, nums, used, curr);
    return result;
  }
  void permute(std::vector<std::vector<int>> &result, std::vector<int> &nums,
               std::vector<bool> &used, std::vector<int> &curr) {
    if (curr.size() == nums.size()) {
      result.push_back(curr);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (!used[i]) {
        used[i] = true;
        curr.push_back(nums[i]);
        permute(result, nums, used, curr);
        curr.pop_back();
        used[i] = false;
      }
    }
  }
};
