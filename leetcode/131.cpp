#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<string>> result;
  vector<vector<string>> partition(string s) {
    vector<string> curr;
    partition(s, curr, 0);
    return result;
  }
  void partition(string &s, vector<string> &curr, int i) {
    if (i == s.size()) {
      result.push_back(curr);
      return;
    }
    for (int j = i; j < s.size(); ++j) {
      string temp = s.substr(i, j - i + 1);
      if (isPalindrome(temp)) {
        curr.push_back(temp);
        partition(s, curr, j + 1);
        curr.pop_back();
      }
    }
  }
  bool isPalindrome(string &temp) {
    int start = 0;
    int end = temp.size() - 1;
    while (start <= end) {
      if (temp[start] != temp[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};
