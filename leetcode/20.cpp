#include "../leet.h"

class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;
    for (auto c : s) {
      if (c == '(' || c == '[' || c == '{') {
        stack.push(c);
      } else {
        if (stack.empty()) {
          return false;
        } else if (c == ')') {
          if (stack.top() != '(') {
            return false;
          }
        } else if (c == ']') {
          if (stack.top() != '[') {
            return false;
          }
        } else if (c == '}') {
          if (stack.top() != '{') {
            return false;
          }
        }
        stack.pop();
      }
    }
    return stack.empty();
  }
};
