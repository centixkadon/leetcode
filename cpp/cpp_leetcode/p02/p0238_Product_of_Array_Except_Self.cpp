
#include "leetcode.hpp"

class Solution {
public:
  vector<int> productExceptSelf(vector<int> & nums) {
    if (nums.empty()) return {};

    vector<int> ans(nums.size());
    ans[0] = 1;
    for (size_t i = 1; i < ans.size(); ++i) ans[i] = ans[i - 1] * nums[i - 1];

    int k = 1;
    for (size_t i = ans.size() - 1; i < ans.size(); --i) {
      ans[i] *= k;
      k *= nums[i];
    }

    return move(ans);
  }
};

int main() {
  auto cerr_buffer = cerr.rdbuf(nullptr);
  {
    auto check = solve(&Solution::productExceptSelf);
    cerr.rdbuf(cerr_buffer);
    cerr.rdbuf(nullptr);
    check({}, {});
    check({ 1 }, { 2 });
    check({ 5, 3 }, { 3, 5 });
    check({ 35, 14, 10 }, { 2, 5, 7 });
    check({ 24, 12, 8, 6 }, { 1, 2, 3, 4 });
  }
  cerr.rdbuf(cerr_buffer);
  return 0;
}

Settings;
