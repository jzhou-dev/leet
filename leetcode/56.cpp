#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> result;
    std::sort(intervals.begin(), intervals.end());
    int start = -1;
    int end = -1;
    for (const auto &interval : intervals) {
      if (start == -1 && end == -1) {
        start = interval[0];
        end = interval[1];
      } else if (interval[0] >= start && interval[0] <= end) {
        if (interval[1] >= end) {
          end = interval[1];
        }
      } else {
        result.push_back({start, end});
        start = interval[0];
        end = interval[1];
      }
    }
    if (start != -1 && end != -1) {
      result.push_back({start, end});
    }
    return result;
  }
};
