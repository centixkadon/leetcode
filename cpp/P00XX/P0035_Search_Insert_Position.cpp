
#include "leetcode.hpp"

class Solution {
public:
  int searchInsert(vector<int> & nums, int target) {
    size_t l = 0, r = nums.size();
    while (l < r) {
      size_t m = (l + r) >> 1;
      if (nums[m] < target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }
};

int main() {
  {
    auto check = solve(&Solution::searchInsert);
    check(0, { 1, 3, 5, 6 }, 0);
    check(0, { 1, 3, 5, 6 }, 1);
    check(1, { 1, 3, 5, 6 }, 2);
    check(1, { 1, 3, 5, 6 }, 3);
    check(2, { 1, 3, 5, 6 }, 4);
    check(2, { 1, 3, 5, 6 }, 5);
    check(3, { 1, 3, 5, 6 }, 6);
    check(4, { 1, 3, 5, 6 }, 7);
    check(0, {}, 1);
    check(0, { 1 }, 0);
    check(0, { 1 }, 1);
    check(1, { 1 }, 2);
  }
  return 0;
}

Settings;
