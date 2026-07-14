#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>>
  findWinners(std::vector<std::vector<int>> &matches) {
    std::vector<std::vector<int>> result(2);
    std::map<int, int> losses;
    for (int i = 0; i < matches.size(); ++i) {
      losses[matches[i][1]] += 1;
      losses[matches[i][0]] += 0;
    }
    for (auto loss : losses) {
      if (loss.second == 0) {
        result[0].push_back(loss.first);
      } else if (loss.second == 1) {
        result[1].push_back(loss.first);
      }
    }
    return result;
  }
};
