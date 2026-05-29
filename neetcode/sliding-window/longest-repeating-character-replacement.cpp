#include "leet.h"

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int max_len = 0;
        pair<char, int> max_freq = {'\n', 0};
        unordered_map<char, int> store;
        for (int r = 0; r < s.size(); r++) {
            if (store.find(s[r]) != store.end()) {
                store[s[r]]++;
            } else {
                store.insert({s[r], 1});
            }

            if (store[s[r]] > max_freq.second) {
                max_freq = {s[r], store[s[r]]};
            }

            while (r - l - max_freq.second + 1 > k) {
                store[s[l]]--;
                if (store[s[l]] > max_freq.second) {
                    max_freq = {s[l], store[s[l]]};
                }
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};
