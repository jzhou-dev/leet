#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> result;
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<int> curr;
    combinationSum(candidates, target, curr, 0);
    return result;
  }
  void combinationSum(vector<int> &candidates, int target, vector<int> &curr,
                      int i) {
    if (target <= 0 || i >= candidates.size()) {
      if (target == 0) {
        result.push_back(curr);
      }
      return;
    }
    curr.push_back(candidates[i]);
    combinationSum(candidates, target - candidates[i], curr, i);
    curr.pop_back();
    combinationSum(candidates, target, curr, i + 1);
  }
};
