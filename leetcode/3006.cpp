#include "../leet.h"

class Solution {
public:
  std::vector<int> beautifulIndices(std::string s, std::string a, std::string b,
                                    int k) {
    std::vector<int> aixs;
    std::vector<int> bixs;
    std::vector<int> result;
    int a_size = a.size();
    int b_size = b.size();
    int s_size = s.size();
    for (int i = 0; i < s.size(); ++i) {
      if (i <= s_size - a_size && s.substr(i, a.size()) == a) {
        aixs.push_back(i);
      }
      if (i <= s_size - b_size && s.substr(i, b.size()) == b) {
        bixs.push_back(i);
      }
    }
    int i = 0;
    int j = 0;
    while (i < aixs.size() && j < bixs.size()) {
      if (bixs[j] < aixs[i] - k) {
        j++;
      } else {
        if (std::abs(aixs[i] - bixs[j]) <= k) {
          result.push_back(aixs[i]);
        }
        i++;
      }
    }
    return result;
  }
};
