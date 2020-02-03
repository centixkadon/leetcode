
#include "leetcode.hpp"

class Solution {
public:
  int findDuplicate(vector<int> & nums) {
    auto p = nums.front(), q = nums.front();
    do {
      p = nums[p];
      q = nums[nums[q]];
    } while (p != q);

    p = nums.front();
    while (p != q) {
      p = nums[p];
      q = nums[q];
    }
    return p;
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::findDuplicate);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(2, { 1, 3, 4, 2, 2 });
    check(3, { 3, 1, 3, 4, 2 });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
