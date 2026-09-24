#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size(), false);
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i; j < s.size(); ++j) {
        if ((i == 0 || dp[i - 1]) && words.count(s.substr(i, j - i + 1))) {
          dp[j] = true;
        }
      }
    }
    return dp.back();
  }
};
