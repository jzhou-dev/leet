#include "../leet.h"

class Solution {
public:
  std::vector<std::vector<int>> kSmallestPairs(std::vector<int> &nums1,
                                               std::vector<int> &nums2, int k) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    for (int num : nums1) {
      pq.push({num + nums2[0], 0});
    }
    std::vector<std::vector<int>> result;
    while (k-- && !pq.empty()) {
      int sum = pq.top().first;
      int pos = pq.top().second;
      pq.pop();
      result.push_back({sum - nums2[pos], nums2[pos]});
      if (pos + 1 < nums2.size()) {
        pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
      }
    }
    return result;
  }
};
