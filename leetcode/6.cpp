#include "leet.h"

class Solution {
public:
    string convert(string s, int numRows) {
      if (numRows == 1 || numRows >= s.size()) {
        return s;
      }
      vector<string> diag(numRows);
      int i = 0;
      int direction = 1;
      for (const auto& c : s) {
        diag[i].push_back(c);
        if (i == 0) {
          direction = 1;
        }
        if (i == numRows-1) {
          direction = -1;
        }
        i+=direction;
      }
      string result = "";
      for (const auto& d : diag) {
        result+=d;
      }
      return result;
    }
};
