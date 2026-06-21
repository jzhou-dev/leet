#include "leet.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int i = 0;
        int len = words.size()*words[0].size();
        int word_len = words[0].size();
        vector<int> result;
        unordered_map<string, int> s_freq;
        for (const auto& word : words) {
          s_freq[word]++;
        }
        while (i+len <= s.size()) {
          unordered_map<string, int> temp_freq = s_freq;
          for (int j = 0; j < len; j+=word_len) {
            string sub = s.substr(i+j, word_len);
            if (temp_freq.count(sub)) {
              temp_freq[sub] == 1 ? temp_freq.erase(sub) : temp_freq[sub]--;
            } else {
              break;
            }
          }
          if (temp_freq.empty()) {
            result.push_back(i);
          }
          i++;
        }
        return result;
    }
};
