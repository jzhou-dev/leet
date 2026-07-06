#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> result;
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::vector<int> combination;
    std::sort(candidates.begin(), candidates.end());
    combinationSum2(candidates, combination, 0, target);
    return result;
  }
  void combinationSum2(std::vector<int> &candidates,
                       std::vector<int> &combination, int start, int target) {
    if (target <= 0) {
      if (target == 0)
        result.push_back(combination);
      return;
    }
    int i = start;
    while (i < candidates.size()) {
      combination.push_back(candidates[i]);
      combinationSum2(candidates, combination, i + 1, target - candidates[i]);
      while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
        ++i;
      }
      combination.pop_back();
      ++i;
    }
  }
};
