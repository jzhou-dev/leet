#include "leet.h"

class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        string para = "";
        generateParanthesis(n, 0, 0, para);
        return result;
    }
    void generateParanthesis(int n, int open, int close, string& para) {
        if (open == n && close == n) {
            result.push_back(para);
            return;
        }
        if (open < n) {
            para.push_back('(');
            generateParanthesis(n, open+1, close, para);
            para.pop_back();
        } 
        if (close < open) {
            para.push_back(')');
            generateParanthesis(n, open, close+1, para);
            para.pop_back();
        }
    }

};
