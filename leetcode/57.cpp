#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
                                       std::vector<int> &newIntervals) {
    std::vector<std::vector<int>> result;
    int i = 0;
    while (i < intervals.size()) {
      if (intervals[i][0] > newIntervals[1]) {
        result.push_back(newIntervals);
        result.insert(result.end(), intervals.begin() + i, intervals.end());
        break;
      }
      if (newIntervals[0] >= intervals[i][0] &&
          newIntervals[0] <= intervals[i][1]) {
        newIntervals[0] = intervals[i][0];
        if (intervals[i][1] >= newIntervals[1]) {
          newIntervals[1] = intervals[i][1];
        }
      } else if (newIntervals[1] >= intervals[i][0] &&
                 newIntervals[1] <= intervals[i][1]) {
        newIntervals[1] = intervals[i][1];
      } else if (intervals[i][1] < newIntervals[0] ||
                 intervals[i][0] > newIntervals[1]) {
        result.push_back(intervals[i]);
      }
      ++i;
    }
    if (i == intervals.size()) {
      result.push_back(newIntervals);
    }
    return result;
  }
};
