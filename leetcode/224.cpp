#include "../leet.h"

class Solution {
public:
  int calculate(std::string s) {
    long long curr = 0;
    long long result = 0;
    int sign = 1;
    std::stack<std::pair<int, int>> store;
    for (auto c : s) {
      if (isdigit(c)) {
        curr = curr * 10 + (c - '0');
      } else if (c == '+') {
        result += curr * sign;
        sign = 1;
        curr = 0;
      } else if (c == '-') {
        result += curr * sign;
        sign = -1;
        curr = 0;
      } else if (c == '(') {
        store.push({result, sign});
        sign = 1;
        result = 0;
      } else if (c == ')') {
        result += curr * sign;
        curr = 0;
        result *= store.top().second;
        result += store.top().first;
        store.pop();
      }
    }
    result += sign * curr;
    return result;
  }
};
