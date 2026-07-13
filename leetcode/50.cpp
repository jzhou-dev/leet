#include "../leet.h"

class Solution {
public:
  double myPow(double x, int n) {
    double result = 1;
    if (x == 1)
      return 1;
    if (x == -1 && n % 2 == 0) {
      return 1;
    } else if (x == -1 && n % 2 == 1) {
      return -1;
    }
    if (x == 0)
      return 0;
    for (int i = 0; i < std::abs(double(n)); i++) {
      result *= x;
    }
    if (n < 0) {
      result = 1 / result;
    }
    return result;
  }
};
