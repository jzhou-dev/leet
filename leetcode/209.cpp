#include "leet.h"

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int l = 0;
    int r = 0;
    int total = 0;
    int min_len = 0;
    while (r < nums.size()) {
      total += nums[r];
      r++;
      while (total >= target && l < r) {
        min_len = min_len == 0 ? r - l : min(min_len, r - l);
        total -= nums[l];
        l++;
      }
    }
    return min_len;
  }
};
