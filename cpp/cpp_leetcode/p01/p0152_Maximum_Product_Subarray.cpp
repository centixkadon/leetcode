
#include "leetcode.hpp"

class Solution {
public:
  int maxProduct(vector<int> & nums) {
    int dpmin, dpmax;
    int ans = dpmin = dpmax = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
      tie(dpmin, dpmax) = minmax(dpmin * nums[i], dpmax * nums[i]);
      dpmin = min(dpmin, nums[i]);
      dpmax = max(dpmax, nums[i]);
      ans = max(ans, max(dpmin, dpmax));
    }

    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::maxProduct);
    check(1, { 1 });
    check(-1, { -1 });
    check(6, { 2, 3, -2, 4 });
    check(0, { -2, 0, -1 });
  }
  return 0;
}

Settings;
