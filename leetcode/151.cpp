#include "leet.h"

class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int start = s.size()-1;
        for (int i = s.size()-1; i>=0; i--) {
          if ((i == s.size()-1 && s[i] != ' ') || (i < s.size()-1 && s[i] != ' ' && s[i+1] == ' ')) {
            start = i+1;
          }
          if ((i == 0 && s[i] != ' ') || (i > 0 && s[i] != ' ' && s[i-1] == ' ')) {
            result+=s.substr(i, start-i)+' ';
          }
        }
        result.pop_back();
        return result;
    }
};
