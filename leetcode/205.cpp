class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
          return false;
        }
        std::unordered_map<char, char> ts;
        std::unordered_map<char, char> st;
        for (int i = 0; i < s.size(); ++i) {
          if (!st.count(s[i]) && !ts.count(t[i])) {
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
          } else {
            if (st[s[i]] != t[i] || ts[t[i]] != s[i]) {
              return false;
            }
          }
        }
        return true;
    }
};
