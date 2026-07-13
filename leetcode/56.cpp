#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty())
      return intervals;
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> result;
    std::vector<int> curr = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
      std::vector<int> interval = intervals[i];
      if (curr[1] < interval[0]) {
        result.push_back(curr);
        curr = interval;
      } else {
        if (curr[1] < interval[1]) {
          curr[1] = interval[1];
        }
      }
    }
    result.push_back(curr);
    return result;
  }
};
