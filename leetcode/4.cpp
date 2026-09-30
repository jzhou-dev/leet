#include <vector>
using namespace std;
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    bool med = len1 + len2 % 2 == 0 ? true : false;
    int left = 0;
    int right = len1;
    // part1 + part2 = (len1+len2+1) / 2
    while (left <= right) {
      int part1 = (left + right) / 2;
      int part2 = (len1 + len2 + 1) / 2 - part1;
      int maxLeft1 = part1 == 0 ? INT_MIN : nums1[part1 - 1];
      int minRight1 = part1 == len1 ? INT_MAX : nums1[part1];
      int maxLeft2 = part2 == 0 ? INT_MIN : nums2[part2 - 1];
      int minRight2 = part2 == len2 ? INT_MAX : nums2[part2];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
        if (med) {
          cout << "median" return (max(maxLeft1, maxLeft2) +
                                   min(minRight1, minRight2)) /
                      2;
        } else {
          return max(maxLeft1, maxLeft2);
        }
      } else if (maxLeft1 > minRight2) {
        right = part1 - 1;
      } else {
        left = part1 + 1;
      }
    }
    return -1;
  }
};
