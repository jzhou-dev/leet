#include "leet.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int i = 0;
        int start = 0;
        string result = "";
        unordered_map<char, int> freq;
        unordered_map<char, int> store;
        for (const auto& i : t) {
          freq[i]++;
        }
        int need = t.size();
        int have = 0;
        while (i < s.size()) {
          if (freq.count(s[i])) {
            store[s[i]]++;
            if (store[s[i]] <= freq[s[i]]) {
              have++;
            }
          }
          if (have == need) { 
            while (have > need-1 && start < s.size()) {
              if (freq.count(s[start])) {
                store[s[start]]--;
                if (store[s[start]] < freq[s[start]]) {
                  if (result == "" || i-start+1<result.size()) {
                    result = s.substr(start, i-start+1);
                  }
                  have--;
                }
              }
              start++;
            }
            while (!freq.count(s[start]) && start < s.size()) {
              start++;
            }
          }
          i++;
        }
        return result;
    }
};
