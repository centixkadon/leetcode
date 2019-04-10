
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> & nums, int target) {
    if (nums.size() < 4) return {};

    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 3; ++i) {
      for (size_t j = i + 1; j < nums.size() - 2; ++j) {
        size_t l = j + 1, r = nums.size() - 1;
        int sum_target = target - nums[i] - nums[j];
        while (l < r) {
          int sum = nums[l] + nums[r];
          if (sum < sum_target)
            ++l;
          else if (sum > sum_target)
            --r;
          else {
            ans.push_back({ nums[i], nums[j], nums[l], nums[r] });
            while ((l < r) && (nums[l] == nums[l + 1])) ++l;
            while ((l < r) && (nums[r] == nums[r - 1])) --r;
            ++l;
            --r;
          }
          while ((j < nums.size() - 3) && (nums[j] == nums[j + 1])) ++j;
        }
        while ((i < nums.size() - 4) && (nums[i] == nums[i + 1])) ++i;
      }
    }

    return move(ans);
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::fourSum);
    check({}, {}, 0);
    check({}, { 0, 0, 0 }, 0);
    check({ { 0, 0, 0, 0 } }, { 0, 0, 0, 0 }, 0);
    check({ { -1, -1, 1, 1 } }, { -1, 1, -1, 1 }, 0);
    check({ { -1, -1, -1, 3 } }, { -1, -1, -1, -1, -1, -1, -1, 3 }, 0);
    check({ { -1, 0, 0, 1 }, { -2, -1, 1, 2 }, { -2, 0, 0, 2 } }, { 1, 0, -1, 0, -2, 2 }, 0);
  }
  return 0;
}

Settings;
