#include "vector"
using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 1) {
      return n;
    }
    int p1 = 1;
    int p2 = 1;
    int curr = 0;
    for (int i = 2; i <= n; ++i) {
      int temp = curr;
      curr = p1 + p2;
      swap(p1, p2);
      p2 = temp;
    }
    return curr;
  }
};
