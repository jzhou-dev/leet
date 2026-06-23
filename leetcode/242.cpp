#include "../leet.h"

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::unordered_map<char, int> freq;
    for (const auto &i : s) {
      freq[i]++;
    }
    int need = freq.size();
    for (const auto &i : t) {
      freq[i]--;
      if (freq[i] == 0) {
        need--;
      }
      if (freq[i] < 0) {
        return false;
      }
    }
    return need == 0;
  }
};
