
#include "leetcode.hpp"

class Solution {
public:
  bool nextPermute(vector<int> & nums) {
    if (nums.size() < 2) return false;
    for (size_t i = nums.size() - 1; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        for (size_t j = nums.size() - 1; j >= i; --j) {
          if (nums[j] > nums[i - 1]) {
            auto tmp = nums[j];
            nums[j] = nums[i - 1];
            nums[i - 1] = tmp;
            for (size_t k = i; k < ((i + nums.size()) >> 1); ++k) {
              auto tmp = nums[k];
              nums[k] = nums[nums.size() + i - k - 1];
              nums[nums.size() + i - k - 1] = tmp;
            }
            return true;
          }
        }
        break;
      }
    }
    return false;
  }
  vector<vector<int>> permuteUnique(vector<int> & nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    ans.push_back(nums);
    while (nextPermute(nums)) ans.push_back(nums);
    return move(ans);
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::permuteUnique);
    check({ { 1 } }, { 1 });
    check({ { 1, 2 }, { 2, 1 } }, { 1, 2 });
    check({ { 1, 2, 3 }, { 1, 3, 2 }, { 2, 1, 3 }, { 2, 3, 1 }, { 3, 1, 2 }, { 3, 2, 1 } }, { 1, 2, 3 });
    check({ { 1, 1, 2 }, { 1, 2, 1 }, { 2, 1, 1 } }, { 1, 1, 2 });
  }
  return 0;
}

Settings;
