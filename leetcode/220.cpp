#include "../leet.h"

class Solution {
public:
  bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int indexDiff,
                                     int valueDiff) {
    std::vector<std::vector<int>> vals(
        *std::max_element(nums.begin(), nums.end()));
    for (int i = 0; i < nums.size(); ++i) {
      vals[nums[i] - 1].push_back(i);
    }
    int i = 0;
    while (i < vals.size()) {
      if (!vals[i].empty()) {
        for (int j = i + 1; j < i + indexDiff + 1; ++i) {
          int i1 = 0;
          int i2 = 0;
          while (i1 < vals[i].size() && i2 < vals[j].size()) {
          }
        }
      }
    }
    return false;
  }
};
