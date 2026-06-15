#inclue "leet.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int numCycles = gcd(nums.size(), k);
      cout << numCycles << endl;
      for (int i = 0; i < numCycles; i++) {
        int j = i;
        int temp = nums[j];
        for (int x = 0; x < nums.size() / numCycles; x++) {
          j = (j + k) % nums.size();
          int swap = nums[j];
          nums[j] = temp;
          temp = swap;
        }
      }
    }
};
