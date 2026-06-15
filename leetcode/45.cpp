include "leet.h"

class Solution {
public:
    int jump(vector<int>& nums) {
      int maxPos = 0;
      int numJumps = 0;
      int jump = 0;
      for (int i = 0; i < nums.size()-1;i++) {
        maxPos = max(maxPos, nums[i] + i);
        if (i == jump) {
          numJumps++;
          jump=maxPos;
          if (maxPos >= nums.size()-1) {
            break;
          }
        }
      }
      return numJumps;
    }
};


