#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, int> store;
    std::vector<std::vector<std::string>> result;
    for (const auto &s : strs) {
      std::string word = s;
      sort(word.begin(), word.end());
      if (store.count(word)) {
        result[store[word]].push_back(s);
      } else {
        store[word] = result.size();
        result.push_back({s});
      }
    }
    return result;
  }
};
