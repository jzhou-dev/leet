#include "../leet.h"

class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int num_shift = 0;
    while (left != right) {
      left >>= 1;
      right >>= 1;
      num_shift++;
    }
    return left << num_shift;
  }
};
