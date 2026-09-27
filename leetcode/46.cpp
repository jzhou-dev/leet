#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> result;
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> curr;
    vector<bool> used(nums.size(), false);
    permute(nums, curr, used);
    return result;
  }
  void permute(vector<int> &nums, vector<int> &curr, vector<bool> &used) {
    if (curr.size() == nums.size()) {
      result.push_back(curr);
      return;
    }
    for (int j = 0; j < nums.size(); ++j) {
      if (!used[j]) {
        used[j] = true;
        curr.push_back(nums[j]);
        permute(nums, curr, used);
        used[j] = false;
        curr.pop_back();
      }
    }
  }
};
