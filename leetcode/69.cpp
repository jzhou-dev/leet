#include "../leet.h"

class Solution {
public:
  int mySqrt(int x) {
    int left = 0;
    int right = x;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long sqr = mid * mid;
      long nextSqr = (mid + 1) * (mid + 1);
      if (sqr <= long(x) && long(x) < nextSqr) {
        return mid;
      } else if (sqr < long(x)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};
