#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> permutation;
       vector<bool> used(nums.size(), false);
       permute(nums, permutation, used);
       return result; 
    }
    void permute(vector<int>& nums, vector<int>& permutation, vector<bool>& used) {
        if (nums.size() == permutation.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                permutation.push_back(nums[i]);
                used[i] = true;
                permute(nums, permutation, used);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }
};
