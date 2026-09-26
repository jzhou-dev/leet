#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
  unordered_map<char, string> store;
  vector<string> result;
  vector<string> letterCombinations(string digits) {
    store = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    string curr = "";
    letterCombinations(digits, 0, curr);
    return result;
  }
  void letterCombinations(string &digits, int i, string &curr) {
    if (i >= digits.size()) {
      result.push_back(curr);
      return;
    }
    for (auto digit : store[digits[i]]) {
      curr.push_back(digit);
      letterCombinations(digits, i + 1, curr);
      curr.pop_back();
    }
  }
};
