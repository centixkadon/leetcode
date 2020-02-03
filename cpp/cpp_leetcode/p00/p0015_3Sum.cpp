
#include "leetcode.hpp"

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> & nums) {
    map<int, int> m;
    vector<int> unique_nums;
    for (auto num : nums) {
      auto && t = m.insert(pair<int, int>(num, 0));
      if (t.second) unique_nums.push_back(num);
      ++t.first->second;
    }

    vector<vector<int>> ans;
    for (auto num1 : unique_nums) {
      for (auto num2 : unique_nums) {
        if ((num1 > num2) || ((num1 == num2) && (m[num1] < 2))) continue;
        auto num3 = -num1 - num2;
        if (num2 > num3) continue;
        auto && t = m.find(num3);
        if (t == m.end()) continue;
        if (num1 == num2) {
          if ((num2 == num3) && (t->second < 3)) continue;
        } else {
          if ((num2 == num3) && (t->second < 2)) continue;
        }
        ans.push_back({ num1, num2, num3 });
      }
    }

    return move(ans);
  }
};

int main() {
  {
    auto check = solve_unordered(&Solution::threeSum);
    check({}, {});
    check({}, { 0 });
    check({}, { 0, 0 });
    check({}, { 0, 0, 1 });
    check({ { 0, 0, 0 } }, { 0, 0, 0 });
    check({ { -1, -1, 2 } }, { -1, -1, -1, 2 });
    check({ { -1, 0, 1 }, { -1, -1, 2 } }, { -1, 0, 1, 2, -1, -4 });
  }
  return 0;
}

Settings;
