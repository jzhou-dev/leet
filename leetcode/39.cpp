#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> result;
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<int> sum;
    combinationSum(candidates, sum, 0, target);
    return result;
  }
  void combinationSum(std::vector<int> &candidates, std::vector<int> &sum,
                      int start, int target) {
    if (target <= 0) {
      if (target == 0) {
        result.push_back(sum);
      }
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      sum.push_back(candidates[i]);
      combinationSum(candidates, sum, i, target - candidates[i]);
      sum.pop_back();
    }
  }
};
