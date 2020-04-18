
#include "leetcode.hpp"

class Solution {
public:
  void moveZeroes(vector<int> & nums) {
    auto it = nums.begin();
    for (auto & num : nums) {
      if (num) {
        tie(num, *it) = make_tuple(*it, num);
        ++it;
      }
    }
  }

  vector<int> moveZeroesCheck(vector<int> & nums) {
    moveZeroes(nums);
    return move(nums);
  }
};

int main() {
  {
    auto check = solve(&Solution::moveZeroesCheck);
    check({}, {});
    check({ 1, 3, 12, 0, 0 }, { 0, 1, 0, 3, 12 });
  }
  return 0;
}

Settings;
