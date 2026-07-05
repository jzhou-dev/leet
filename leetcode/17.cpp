#include "../leet.h"

class Solution {
public:
  std::vector<std::string> result;
  std::unordered_map<char, std::string> convert = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
  std::vector<std::string> letterCombinations(std::string digits) {
    std::string curr = "";
    letterCombination(digits, curr, 0);
    return result;
  }
  void letterCombination(std::string &digits, std::string &curr, int index) {
    if (index == digits.size()) {
      result.push_back(curr);
      return;
    }
    for (int i = 0; i < convert[digits[index]].size(); ++i) {
      curr.push_back(convert[digits[index]][i]);
      letterCombination(digits, curr, index + 1);
      curr.pop_back();
    }
  }
};
