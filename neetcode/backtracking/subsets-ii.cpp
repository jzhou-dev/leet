#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, subset, 0);
        return result;
    }
    void subsetsWithDup(vector<int>& nums, vector<int>& subset, int i) {
        if (i > nums.size()-1) {
            result.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        subsetsWithDup(nums, subset, i+1);
        while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
            i++;
        }
        subset.pop_back();
        subsetsWithDup(nums, subset, i+1);
    }
};
