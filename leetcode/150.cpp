#include "../leet.h"

class Solution {
public:
  int evalRPN(std::vector<std::string> &tokens) {
    std::stack<int> stack;
    for (auto token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();
        if (token == "+") {
          stack.push(num2 + num1);
        } else if (token == "-") {
          stack.push(num2 - num1);
        } else if (token == "*") {
          stack.push(num2 * num1);
        } else {
          stack.push(num2 / num1);
        }
      } else {
        stack.push(stoi(token));
      }
    }
    return stack.top();
  }
};
