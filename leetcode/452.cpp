#include "../leet.h"

class Solution {
public:
  int findMinArrowShots(std::vector<std::vector<int>> &points) {
    sort(points.begin(), points.end());
    int max = points[0][1];
    int result = 1;
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > max) {
        result++;
        max = points[i][1];
      } else if (points[i][1] < max) {
        max = points[i][1];
      }
    }
    return result;
  }
};
