#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int result = *max_element(nums.begin(), nums.end());
    int curr_max = 1;
    int curr_min = 1;
    for (int num : nums) {
      int temp = curr_max * num;
      curr_max = max({temp, curr_min * num, num});
      curr_min = min({temp, curr_min * num, num});
      result = max(curr_max, result);
    }
    return result;
  }
};
