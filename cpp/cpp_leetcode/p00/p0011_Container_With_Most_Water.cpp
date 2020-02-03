
#include "leetcode.hpp"

class Solution {
public:
  int maxArea(vector<int> & height) {
    size_t l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
      ans = max(ans, static_cast<int>((r - l) * min(height[l], height[r])));
      if (height[l] <= height[r])
        ++l;
      else
        --r;
    }
    return ans;
  }
};

int main() {
  {
    auto check = solve(&Solution::maxArea);
    check(1, { 1, 1000 });
    check(10, { 1, 1, 10, 10, 1, 1 });
    check(5, { 1, 1, 2, 2, 1, 1 });
  }
  return 0;
}

Settings;
