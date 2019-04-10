
#include "leetcode.hpp"

class Solution {
public:
  int threeSumClosest(vector<int> & nums, int target) {
    int ans = 0;
    sort(nums.begin(), nums.end());

    int diff = numeric_limits<int>::max();
    for (size_t i = 0; i < nums.size() - 2; ++i) {
      size_t l = i + 1, r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum < target)
          ++l;
        else if (sum > target)
          --r;
        else
          return target;

        int k = abs(sum - target);
        if (k < diff) {
          diff = k;
          ans = sum;
        }
      }
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::threeSumClosest);
    check(2, { -1, 2, 1, -4 }, 1);
  }
  return 0;
}

Settings;
