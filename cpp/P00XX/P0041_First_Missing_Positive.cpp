
#include "leetcode.hpp"

class Solution {
public:
  int firstMissingPositive(vector<int> & nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
      while (0 < nums[i] && nums[i] <= nums.size() && nums[i] != i + 1) {
        size_t tmp = nums[i];
        if (nums[tmp - 1] == tmp) break;
        nums[i] = nums[tmp - 1];
        nums[tmp - 1] = tmp;
      }
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
  }
};

int main() {
  {
    auto check = solve(&Solution::firstMissingPositive);
    check(3, { 1, 2, 0 });
    check(2, { 3, 4, -1, 1 });
    check(1, { 7, 8, 9, 11, 12 });
    check(1, {});
    check(2, { 1 });
    check(2, { 1, 1 });
    check(1, { 2 });
  }
  return 0;
}

Settings;
