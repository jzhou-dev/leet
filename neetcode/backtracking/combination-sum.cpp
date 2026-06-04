#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> sum_nums;
        combinationSum(nums, sum_nums, 0, target, 0);
        return result;
    }

    void combinationSum(vector<int>& nums, vector<int>& sum_nums, int sum, int target, int i) {
        if (i > nums.size() - 1 || sum >= target) {
            if (sum == target) {
                result.push_back(sum_nums);
            }
            return;
        }
        sum += nums[i];
        sum_nums.push_back(nums[i]);
        combinationSum(nums, sum_nums, sum, target, i);
        sum -= nums[i];
        sum_nums.pop_back();
        combinationSum(nums, sum_nums, sum, target, i+1);
    }
};
