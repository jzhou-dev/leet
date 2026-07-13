#include "../leet.h"

class Solution {
public:
  int findMinDifference(std::vector<std::string> &timePoints) {
    std::vector<int> convert;
    for (std::string time : timePoints) {
      int minutes =
          std::stoi(time.substr(0, 2)) * 60 + std::stoi(time.substr(3, 2));
      convert.push_back(minutes);
    }
    int min_diff = INT_MAX;
    std::sort(convert.begin(), convert.end());
    for (int i = 0; i < convert.size(); ++i) {
      int diff = i == convert.size() - 1
                     ? std::abs(convert[i] - (1440 + convert[0]))
                     : std::abs(convert[i] - convert[i + 1]);
      min_diff = std::min(diff, min_diff);
    }
    return min_diff;
  }
};
