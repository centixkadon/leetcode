
#include "leetcode.hpp"

class Solution {
public:
  int removeElement(vector<int> & nums, int val) {
    if (nums.empty()) return 0;
    auto it = nums.begin();
    for (auto const & num : nums) {
      if (num != val) *it++ = num;
    }
    return it - nums.begin();
  }
  vector<int> removeElementCheck(vector<int> & nums, int val) {
    return move(vector<int>(nums.begin(), nums.begin() + removeElement(nums, val)));
  }
};

int main() {
  {
    auto check = solve(&Solution::removeElementCheck);
    check({}, {}, 0);
    check({ 1 }, { 1 }, 2);
    check({}, { 1 }, 1);
    check({ 2, 2 }, { 3, 2, 2, 3 }, 3);
    check({ 0, 1, 3, 0, 4 }, { 0, 1, 2, 2, 3, 0, 4, 2 }, 2);
  }
  return 0;
}

Settings;
