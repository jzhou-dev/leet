#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  string evaluate(string s, vector<vector<string>> &knowledge) {
    unordered_map<string, string> store;
    for (auto i : knowledge) {
      store[i[0]] = i[1];
    }
    int i = 0;
    string result = "";
    while (i < s.size()) {
      if (s[i] != '(') {
        result.push_back(s[i]);
        ++i;
        continue;
      }
      int start = i + 1;
      while (s[i] != ')') {
        ++i;
      }
      string curr = s.substr(start, i - start);
      store.count(curr) ? result += store[curr] : result += "?";
      ++i;
    }
    return result;
  }
};
