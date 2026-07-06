#include "../leet.h"

class Solution {
public:
  std::vector<std::string> result;
  std::vector<std::string> generateParenthesis(int n) {
    std::string curr = "";
    generateParenthesis(n, curr, 0, 0);
    return result;
  }
  void generateParenthesis(int n, std::string curr, int open, int closed) {
    if (open == n && closed == n) {
      result.push_back(curr);
      return;
    }
    if (open < n) {
      curr.push_back('(');
      generateParenthesis(n, curr, open + 1, closed);
      curr.pop_back();
    }
    if (closed < open) {
      curr.push_back(')');
      generateParenthesis(n, curr, open, closed + 1);
      curr.pop_back();
    }
  }
  bool validParenthesis(std::string curr) {
    int closed = 0;
    while (!curr.empty()) {
      if (curr.back() == ')') {
        closed++;
      } else {
        closed--;
      }
      if (closed < 0) {
        return false;
      }
      curr.pop_back();
    }
    return true;
  }
};
