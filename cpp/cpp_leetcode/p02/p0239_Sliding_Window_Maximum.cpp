
#include "leetcode.hpp"

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> & nums, int k) {
    vector<int> ans;
    deque<size_t> v;
    ans.reserve(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      while (!v.empty() && v.front() + size_t(k) <= i) v.pop_front();
      while (!v.empty() && nums[v.back()] <= nums[i]) v.pop_back();
      v.push_back(i);
      if (size_t(k) <= i + 1) ans.push_back(nums[v.front()]);
    }
    return move(ans);
  }
};

int main() {
  {
    auto check = solve(&Solution::maxSlidingWindow);
    check({ 10 }, { 10 }, 1);
    check({ 20 }, { 10, 20 }, 2);
    check({ 3, 3, 5, 5, 6, 7 }, { 1, 3, -1, -3, 5, 3, 6, 7 }, 3);
  }
  return 0;
}

Settings;
