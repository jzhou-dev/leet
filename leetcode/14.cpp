#include "leet.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++) {
          char curr = strs[0][i];
          bool common = true;
          for (int j = 0; j < strs.size(); j++) {
            if (strs[j][i] != strs[0][i]) {
              common = false;
              break;
            }
          }
          if (common) {
            prefix.push_back(strs[0][i]);
          } else {
            break;
          }
        }
        return prefix;
    }
};
