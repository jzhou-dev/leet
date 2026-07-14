#include "../leet.h"

class Solution {
public:
  bool checkStraightLine(std::vector<std::vector<int>> &coordinates) {
    int slope = 0;
    if (coordinates[0][0] == coordinates[1][0]) {
      slope = 1;
    } else {
      slope = (coordinates[1][1] - coordinates[0][1]) /
              (coordinates[1][0] - coordinates[0][0]);
    }
    double y_int = (coordinates[0][1] - (slope * coordinates[0][0]));
    for (int i = 2; i < coordinates.size(); ++i) {
      if (slope == 1 && coordinates[i][0] != coordinates[i - 1][0]) {
        return false;
      } else if (slope == 0 && coordinates[i][1] != coordinates[i - 1][1]) {
        return false;
      } else if (coordinates[i][1] != slope * coordinates[i][0] + y_int) {
        return false;
      }
    }
    return true;
  }
};
