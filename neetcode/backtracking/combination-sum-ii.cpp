#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> nums;
        set<int> seen;
        sort(candidates.begin(), candidates.end());
        combinationSum2(candidates, nums, target, 0);
        return result;
    }
    void combinationSum2(vector<int>& candidates, vector<int>& nums, int target, int i) {
        if (i > candidates.size() - 1 || target <= 0) {
            if (target == 0) {
                result.push_back(nums);
            }
            return;
        }
        target -= candidates[i];
        nums.push_back(candidates[i]);
        combinationSum2(candidates, nums, target, i+1);
        target += candidates[i];
        nums.pop_back();
        while (i < candidates.size()-1 && candidates[i] == candidates[i+1]) {
            i++;
        }
        combinationSum2(candidates, nums, target, i+1);
    }
};
