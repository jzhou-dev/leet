#include "../leet.h"

class Solution {
public:
  bool wordBreak(std::string &s, std::vector<std::string> &wordDict) {
    std::unordered_set<std::string> store(wordDict.begin(), wordDict.end());
    int start = 0;
    int len = 1;
    while (start + len < s.size()) {
      if (store.count(s.substr(start, len))) {
        start += len;
        len = 1;
      } else {
        len++;
      }
    }
    return !store.count(s.substr(start)) ? false : true;
  }
};
