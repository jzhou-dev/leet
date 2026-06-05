#include "leet.h"

class Solution {
public:
    string result = "";
    string getHappyString(int n, int k) {
        string characters = "abc";
        string happyString = "";
        vector<bool> used(n, false);
        getHappyString(n, k, happyString, characters, used);
        return result;
    }
    void getHappyString(int n, int& k, string& happyString, string& characters, vector<bool>& used) {
        if (happyString.size() == n) {
            k--;
            if (k == 0) {
                result = happyString;
            }
            return;
        }
        for (int i = 0; i < characters.size(); i++) {
            if (happyString.empty() || happyString.back() != characters[i]) {
                happyString.push_back(characters[i]);
                used[i] = true;
                getHappyString(n, k, happyString, characters, used);
                happyString.pop_back();
                used[i] = false;
            }
        }
    }

    
};