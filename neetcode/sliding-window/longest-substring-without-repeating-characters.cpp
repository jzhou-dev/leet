#include "leet.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int max_len = 1;
        int l = 0;
        int r = 1;
        set<char> store = {s[0]};
        while (r < s.size()) {
            if (store.find(s[r]) == store.end()){
                store.insert(s[r]);
                max_len = max(max_len, r-l + 1);
                r++;
            } else {
                while (store.find(s[r]) != store.end()) {
                    store.erase(s[l]);
                    l++;
                }
            }
        }
        return max_len;
    }
};