#include "../leet.h"

class MinStack {
public:
  std::vector<int> stack;
  std::stack<int> min;
  void push(int value) {
    stack.push_back(value);
    if (min.empty() || value <= min.top()) {
      min.push(value);
    }
  }
  void pop() {
    if (!min.empty() && stack.back() == min.top()) {
      min.pop();
    }
    stack.pop_back();
  }
  int top() { return stack.back(); }
  int getMin() {
    if (!min.empty()) {
      return min.top();
    }
    return -1;
  }
};
