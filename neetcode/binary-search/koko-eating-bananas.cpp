#include "leet.h"

class Solution {
public:
    int hoursToEat(vector<int> &piles, int speed) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += ceil(piles[i] * 1.0 / speed);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > high) {
                high = piles[i];
            }
        }
        int min = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int hours = hoursToEat(piles, mid);
            if (hours <= h) {
                if (mid < min) {
                    min = mid;
                }
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return min;
    }
};