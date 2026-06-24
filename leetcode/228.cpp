#include "../leet.h"

class Solution {
public:
  std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    int start = 0;
    int end = -1;
    std::vector<std::string> result;
    for (int i = 0; i < nums.size(); ++i) {
      if (end != -1 && nums[end] != nums[i] - 1) {
        nums[end] == nums[start]
            ? result.push_back(std::to_string(nums[start]))
            : result.push_back(std::to_string(nums[start]) + "->" +
                               std::to_string(nums[end]));
        start = i;
      }
      end = i;
    }
    if (end != -1) {
      nums[end] == nums[start]
          ? result.push_back(std::to_string(nums[start]))
          : result.push_back(std::to_string(nums[start]) + "->" +
                             std::to_string(nums[end]));
    }
    return result;
  }
};
