#include "../leet.h"

class Solution {
public:
  std::string longestPalindrome(std::string s) {
    std::vector<std::vector<bool>> palindromes(
        s.size() + 1, std::vector<bool>(s.size() + 1, false));
    for (int i = 0; i < s.size() + 1; ++i) {
      palindromes[i][0] = true;
      palindromes[i][1] = true;
    }
    int start = 0;
    int len = 1;
    for (int i = 2; i <= s.size(); ++i) {
      for (int j = 0; j + i - 1 < s.size(); ++j) {
        if (palindromes[j + 1][i - 2] && s[j + i - 1] == s[j]) {
          palindromes[j][i] = true;
          start = j;
          len = i;
        }
      }
    }
    return s.substr(start, len);
  }
};
