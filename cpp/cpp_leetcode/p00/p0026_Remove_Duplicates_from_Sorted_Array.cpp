
#include "leetcode.hpp"

class Solution {
public:
  int removeDuplicates(vector<int> & nums) {
    if (nums.empty()) return 0;
    auto it = nums.begin();
    for (auto const & num : nums) {
      if (*it != num) {
        *++it = num;
      }
    }
    return it - nums.begin() + 1;
  }
  vector<int> removeDuplicatesCheck(vector<int> & nums) {
    return move(vector<int>(nums.begin(), nums.begin() + removeDuplicates(nums)));
  }
};

int main() {
  {
    auto check = solve(&Solution::removeDuplicatesCheck);
    check({}, {});
    check({ 1 }, { 1 });
    check({ 1, 2 }, { 1, 2 });
    check({ 1, 2 }, { 1, 1, 2 });
    check({ 0, 1, 2, 3, 4 }, { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 });
  }
  return 0;
}

Settings;
