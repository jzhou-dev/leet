#include "../leet.h"

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0 || n == 1) {
      return 1;
    }
    std::vector<int> steps(n + 1);
    steps[0] = 1;
    steps[1] = 1;
    for (int i = 2; i < steps.size(); ++i) {
      steps[i] = steps[i - 1] + steps[i - 2];
    }
    return steps.back();
  }
};
