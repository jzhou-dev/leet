#include "leet.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int l = 0;
        int r = 0;
        int max_len = 0;
        while (r < s.size()) {
          for (const auto& pair : freq) {
            cout << pair.first << ": " << pair.second << " ";
          }
          cout << endl;
          freq[s[r]]++;
          r++;
          while (freq[s[r-1]] > 1 && l < r) {
            freq[s[l]] > 0 ? freq[s[l]]-- : freq[s[l]] = 0;
            l++;
          }
          max_len = max(r-l, max_len);
        }
        return max_len;
    }
};
