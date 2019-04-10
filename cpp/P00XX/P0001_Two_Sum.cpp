
#include "leetcode.hpp"

class Solution {
public:
  vector<int> twoSum(vector<int> & nums, int target) {
    map<int, size_t> m;
    for (size_t i = 0; i < nums.size(); ++i) m[nums[i]] = i;
    for (size_t i = 0; i < nums.size(); ++i) {
      auto p = m.find(target - nums[i]);
      if ((p != m.end()) && (i != p->second)) return { static_cast<int>(i), static_cast<int>(p->second) };
    }
    return { 0, 1 };
  }
};

int main() {
  {
    auto check = solve(&Solution::twoSum);
    check({ 0, 1 }, { 2, 7, 11, 15 }, 9);
    check({ 1, 3 }, { 2, 7, 11, 15 }, 22);
    check({ 1, 2 }, { 3, 2, 4 }, 6);
  }
  return 0;
}

Settings;
