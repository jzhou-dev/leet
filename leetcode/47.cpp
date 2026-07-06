#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    std::vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    permuteUnique(result, nums, used, curr);
    return result;
  }
  void permuteUnique(std::vector<std::vector<int>> &result,
                     std::vector<int> &nums, std::vector<bool> &used,
                     std::vector<int> &curr) {
    if (curr.size() == nums.size()) {
      result.push_back(curr);
      return;
    }
    int i = 0;
    while (i < nums.size()) {
      if (!used[i]) {
        used[i] = true;
        curr.push_back(nums[i]);
        permuteUnique(result, nums, used, curr);
        used[i] = false;
        curr.pop_back();
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
          i++;
        }
      }
      i++;
    }
  }
};
