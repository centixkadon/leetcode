
#include "leetcode.hpp"

class Solution {
public:
  int search(vector<int> & nums, int target) {
    if (nums.empty()) return -1;
    size_t l = 0, r = nums.size();
    if (target == nums[l]) return l;
    while (l + 1 < r) {
      size_t m = (l + r) >> 1;
      if (nums[l] > nums[r - 1]) {
        if (nums[r - 1] < target && target < nums[l]) return -1;
        if ((nums[l] <= target && target < nums[m]) || (nums[l] > nums[m] && (nums[l] <= target || target < nums[m]))) {
          r = m;
        } else {
          l = m;
        }
      } else {
        if (target < nums[m]) {
          r = m;
        } else {
          l = m;
        }
      }
      if (target == nums[l]) return l;
    }
    return -1;
  }
};

int main() {
  {
    auto check = solve(&Solution::search);
    check(-1, { 4, 5, 6, 7, 0, 1, 2 }, -1);
    check(4, { 4, 5, 6, 7, 0, 1, 2 }, 0);
    check(5, { 4, 5, 6, 7, 0, 1, 2 }, 1);
    check(6, { 4, 5, 6, 7, 0, 1, 2 }, 2);
    check(-1, { 4, 5, 6, 7, 0, 1, 2 }, 3);
    check(0, { 4, 5, 6, 7, 0, 1, 2 }, 4);
    check(1, { 4, 5, 6, 7, 0, 1, 2 }, 5);
    check(2, { 4, 5, 6, 7, 0, 1, 2 }, 6);
    check(3, { 4, 5, 6, 7, 0, 1, 2 }, 7);
    check(-1, { 4, 5, 6, 7, 0, 1, 2 }, 8);
    check(-1, {}, 3);
    check(-1, { 1 }, 0);
    check(0, { 1 }, 1);
    check(-1, { 1 }, 2);
    check(-1, { 1, 2, 3 }, 0);
    check(0, { 1, 2, 3 }, 1);
    check(1, { 1, 2, 3 }, 2);
    check(2, { 1, 2, 3 }, 3);
    check(-1, { 1, 2, 3 }, 4);
  }
  return 0;
}

Settings;
