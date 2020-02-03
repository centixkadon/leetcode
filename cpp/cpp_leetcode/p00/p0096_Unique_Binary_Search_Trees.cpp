
#include "leetcode.hpp"

class Solution {
public:
  int numTrees(int n) {
    vector<int> nums(n + 1);
    nums[0] = 1;
    for (size_t i = 1; i < nums.size(); ++i) {
      nums[i] = 0;
      for (size_t j = 0; j < i; ++j) {
        nums[i] += nums[j] * nums[i - 1 - j];
      }
    }
    return nums[n];
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::numTrees);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check(1, 1);
    check(2, 2);
    check(5, 3);
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
