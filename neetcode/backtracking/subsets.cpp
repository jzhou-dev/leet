#include "leet.h"


                
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> result;
        subsets(nums, result, 0, subset);
        return result;
    }
    void subsets(vector<int>& nums, vector<vector<int>>& result, int i, vector<int>& subset) {
        if (i > nums.size()) {
            result.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        subsets(nums, result, i+1, subset);
        subset.pop_back();
        subsets(nums, result, i+1, subset);
    }
};
                