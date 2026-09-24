#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> store;
    for (auto c : s) {
      if (c == '(' || c == '{' || c == '[') {
        store.push(c);
      } else {
        if (c == ')') {
          if (store.empty() || store.top() != '(') {
            return false;
          }
          store.pop();

        } else if (c == ']') {
          if (store.empty() || store.top() != '[') {
            return false;
          }
          store.pop();
        } else {
          if (store.empty() || store.top() != '{') {
            return false;
          }
          store.pop();
        }
      }
    }
    return store.empty();
  }
};
