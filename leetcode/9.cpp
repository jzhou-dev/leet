#include "../leet.h"

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    long long reverse = 0;
    int temp = x;
    while (x != 0) {
      reverse *= 10;
      reverse += x % 10;
      x /= 10;
    }
    return temp == reverse;
  }
};
