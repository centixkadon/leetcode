
#include "leetcode.hpp"

class Solution {
public:
  int jump(vector<int> & nums) {
    if (nums.size() < 2) return nums.size() - 1;

    size_t i = 0, j = 0, k = 0;
    size_t ans = 1;

    while (i + nums[i] < nums.size() - 1) {
      while (j < min(nums.size(), i + nums[i] + 1)) {
        if (j + nums[j] > k + nums[k]) k = j;
        ++j;
      }
      ++ans;
      i = k;
    }

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::jump);
    check(2, { 2, 3, 1, 1, 4 });
    check(3, { 5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0 });
    check(0, { 1 });
    check(1, { 1, 1 });
    check(2, { 1, 2, 3 });
  }
  return 0;
}

Settings;
