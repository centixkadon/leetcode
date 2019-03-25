
#include "leetcode.hpp"

class Solution {
public:
  vector<int> searchRange(vector<int> & nums, int target) {
    if (nums.empty()) return { -1, -1 };
    size_t l = 0, r = nums.size();
    while (l < r) {
      size_t m = (l + r) >> 1;
      if (target <= nums[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (l == nums.size() || nums[l] != target) return { -1, -1 };
    int lb = l;
    l = 0, r = nums.size();
    while (l < r) {
      size_t m = (l + r) >> 1;
      if (target < nums[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    int ub = l - 1;
    return { lb, ub };
  }
};

int main() {
  {
    auto check = solve(&Solution::searchRange);
    check({ -1, -1 }, { 5, 7, 7, 8, 8, 10 }, 4);
    check({ 0, 0 }, { 5, 7, 7, 8, 8, 10 }, 5);
    check({ -1, -1 }, { 5, 7, 7, 8, 8, 10 }, 6);
    check({ 1, 2 }, { 5, 7, 7, 8, 8, 10 }, 7);
    check({ 3, 4 }, { 5, 7, 7, 8, 8, 10 }, 8);
    check({ -1, -1 }, { 5, 7, 7, 8, 8, 10 }, 9);
    check({ 5, 5 }, { 5, 7, 7, 8, 8, 10 }, 10);
    check({ -1, -1 }, { 5, 7, 7, 8, 8, 10 }, 11);
    check({ -1, -1 }, {}, 1);
    check({ -1, -1 }, { 1 }, 0);
    check({ 0, 0 }, { 1 }, 1);
    check({ -1, -1 }, { 1 }, 2);
    check({ -1, -1 }, { 1, 3 }, 0);
    check({ 0, 0 }, { 1, 3 }, 1);
    check({ -1, -1 }, { 1, 3 }, 2);
    check({ 1, 1 }, { 1, 3 }, 3);
    check({ -1, -1 }, { 1, 3 }, 4);
    check({ -1, -1 }, { 1, 1 }, 0);
    check({ 0, 1 }, { 1, 1 }, 1);
    check({ -1, -1 }, { 1, 1 }, 2);
    check({ -1, -1 }, { 1, 1, 1 }, 0);
    check({ 0, 2 }, { 1, 1, 1 }, 1);
    check({ -1, -1 }, { 1, 1, 1 }, 2);
  }
  return 0;
}

Settings;
