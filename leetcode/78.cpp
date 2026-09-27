#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> result;
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> curr;
    subsets(nums, curr, 0);
    return result;
  }
  void subsets(vector<int> &nums, vector<int> &curr, int i) {
    if (i == nums.size()) {
      result.push_back(curr);
      return;
    }
    curr.push_back(nums[i]);
    subsets(nums, curr, i + 1);
    curr.pop_back();
    subsets(nums, curr, i + 1);
  }
};
