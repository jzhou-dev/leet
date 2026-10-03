#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < wordDict.size(); ++j) {
        if (dp[i - 1] && s.substr(i - 1, wordDict[j].size()) == wordDict[j]) {
          dp[i + wordDict[j].size() - 1] = true;
        }
      }
    }
    return dp.back();
  }
};
