#include <vector>
using namespace std;
class Solution {
public:
  vector<string> result;
  vector<string> generateParenthesis(int n) {
    string curr = "";
    generateParenthesis(n, curr, 0, 0);
    return result;
  }
  void generateParenthesis(int n, string &curr, int left, int right) {
    if (curr.size() == n * 2) {
      result.push_back(curr);
      return;
    }
    if (left < n) {
      curr.push_back('(');
      generateParenthesis(n, curr, left + 1, right);
      curr.pop_back();
    }
    if (right < left) {
      curr.push_back(')');
      generateParenthesis(n, curr, left, right + 1);
      curr.pop_back();
    }
  }
};
