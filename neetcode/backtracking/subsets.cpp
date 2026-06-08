#include "leet.h"
                
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(nums, subset, 0);
        return result;
    }
    void backtrack(vector<int>& nums, vector<int>& subset, int i) {
        if (i > nums.size() - 1) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        backtrack(nums, subset, i+1);
        subset.pop_back();
        backtrack(nums, subset, i+1);
    }
};
                