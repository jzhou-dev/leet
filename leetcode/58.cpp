#include "leet.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
      int i = s.size()-1;
      int start = -1;
      while (i >= 0) {
        if (s[i] != ' ' && start == -1) {
          start = i;
        }
        if (s[i] == ' ' && start != -1) {
          break;
        }
        i--;
      }
      return start == -1 ? 0 : start-i;
    }
};
