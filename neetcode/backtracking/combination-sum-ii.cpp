#include "leet.h"

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, combination, 0, target);
        return result;
    }
    void backtrack(vector<int>& candidates, vector<int>& combination, int i, int target) {
        if (target <= 0) {
            if (target == 0) {
                result.push_back(combination);
            }
            return;
        }
        if (i > candidates.size() - 1) {
            return;
        }
        combination.push_back(candidates[i]);
        backtrack(candidates, combination, i+1, target-candidates[i]);
        combination.pop_back();
        while (i < candidates.size() - 1 && candidates[i] == candidates[i+1]) {
            i++;
        }
        backtrack(candidates, combination, i+1, target) ;
    }
};

