#include "../leet.h"

class Solution {
public:
  int shortestWordDistance(std::vector<std::string> &words_dict,
                           std::string &word1, std::string &word2) {
    int min_diff = INT_MAX;
    int i1 = -1;
    int i2 = -1;
    for (int i = 0; i < words_dict.size(); ++i) {
      if (words_dict[i] == word1) {
        i1 = i;
      }
      if (words_dict[i] == word2) {
        i2 = i;
      }
      if (i1 != -1 && i2 != -1) {
        min_diff = std::min(std::abs(i2 - i1), min_diff);
      }
    }
    return min_diff;
  }
};
