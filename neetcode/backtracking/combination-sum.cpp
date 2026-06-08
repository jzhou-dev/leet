#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combination;
        backtrack(nums, combination, 0, target);
        return result;
    }
    void backtrack(vector<int>& nums, vector<int>& combination, int start, int target) {
        if (target <= 0) {
            if (target == 0) {
                result.push_back(combination);
            }
            return;
        }
        if (start > nums.size() - 1) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            combination.push_back(nums[i]);
            backtrack(nums, combination, i, target-nums[i]);
            combination.pop_back();
        }
    }

};
