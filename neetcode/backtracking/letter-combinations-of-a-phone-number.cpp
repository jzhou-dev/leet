#include "leet.h"

class Solution {
public:
    vector<string> result;
    unordered_map<int, string> numbers;
    vector<string> letterCombinations(string digits) {
        numbers[2] = "abc";
        numbers[3] = "def";
        numbers[4] = "ghi";
        numbers[5] = "jkl";
        numbers[6] = "mno";
        numbers[7] = "pqrs";
        numbers[8] = "tuv";
        numbers[9] = "wxyz";
        string combination;
        backtrack(digits, combination, 0);
        return result;
    }
    void backtrack(string& digits, string& combination, int i) {
        if (i >= digits.size()) {
            if (combination != "" ) {
                result.push_back(combination);
            }
            return;
        }
        string digit = numbers[digits[i] - '0'];
        for (int j = 0; j < digit.size(); j++) {
            combination.push_back(digit[j]);
            backtrack(digits, combination, i+1);
            combination.pop_back();
        }

    }
};
